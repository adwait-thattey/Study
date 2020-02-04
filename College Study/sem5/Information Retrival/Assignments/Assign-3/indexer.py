import math
import os
import random

import constants
import utils
import shared
from numba import jit, cuda, njit
import numpy as np
from timeit import default_timer as timer


def gen_seed_for_term(term):
    # sum = 0
    # for ix in range(len(term)):
    #     asc_val = ord(term[ix])
    #     sum += (ix + 1) * asc_val

    return int(id(term))


def make_index_vector(term):
    if term in shared.INDEX_VECTORS:
        return

    shared.INDEX_VECTORS[term] = [0] * constants.VECTOR_SIZE
    if term == "**" or term in shared.STOP_WORDS:
        # keep iv of stop words as all 0s
        return

    to_be_replaced = math.ceil(constants.VECTOR_REPLACE_RATIO * constants.VECTOR_SIZE)
    random.seed(gen_seed_for_term(term))

    for _ in range(to_be_replaced):
        shared.INDEX_VECTORS[term][random.randint(0, constants.VECTOR_SIZE - 1)] = random.choice([1, -1])

    return


def get_normalized_line(line):
    line = line.strip('\n').strip().strip('.').strip()
    line = line.split(' ')
    # line = [w for w in line if w not in shared.STOP_WORDS]
    return line


def make_initial_context_vector_for_line(line_list):
    for term in line_list:
        if term not in shared.CONTEXT_VECTORS:
            make_index_vector(term)
            if term not in shared.STOP_WORDS and term != "**":
                shared.CONTEXT_VECTORS[term] = [0]*constants.VECTOR_SIZE


def add_iv_to_cv(term1, term2, weight):
    if term1 in shared.STOP_WORDS or term1 == "**":
        return
    # adds iv of term2 to cv of term1 with weight
    for ix in range(len(shared.CONTEXT_VECTORS[term1])):
        shared.CONTEXT_VECTORS[term1][ix] += weight * shared.INDEX_VECTORS[term2][ix]


def accumulate_context_vectors_for_line(line_list):
    for ix in range(len(line_list)):
        if ix - 1 >= 0:
            add_iv_to_cv(line_list[ix], line_list[ix - 1], constants.WEIGHTS[1])
            if ix - 2 >= 0:
                add_iv_to_cv(line_list[ix], line_list[ix - 2], constants.WEIGHTS[2])

        if ix + 1 < len(line_list):
            add_iv_to_cv(line_list[ix], line_list[ix + 1], constants.WEIGHTS[1])
            if ix + 2 < len(line_list):
                add_iv_to_cv(line_list[ix], line_list[ix + 2], constants.WEIGHTS[2])


def process_line(line):
    line_list = get_normalized_line(line)
    make_initial_context_vector_for_line(line_list)

    accumulate_context_vectors_for_line(line_list)


def process_document(doc):
    if not shared.STOP_WORDS:
        utils.gen_stopwords()

    f = open(os.path.join(constants.parsed_documents_directory_path, doc), mode="r")
    lines = f.readlines()
    f.close()

    for l in lines:
        process_line(l)


def calc_length_of_cv(term):
    length = 0
    for wt in shared.CONTEXT_VECTORS[term]:
        length += (wt ** 2)

    # print(term, length)
    length = math.sqrt(length)
    shared.CONTEXT_VECTORS_LENGTH[term] = length


def normalize_term(term):
    if term not in shared.CONTEXT_VECTORS_LENGTH:
        calc_length_of_cv(term)

    length = shared.CONTEXT_VECTORS_LENGTH[term]
    
    if length > 0:
        shared.CONTEXT_VECTORS[term] = [val / length for val in shared.CONTEXT_VECTORS[term]]
    

def normalize_all_terms():
    for term in shared.CONTEXT_VECTORS:
        normalize_term(term)


def calc_length_of_all_terms():
    for term in shared.CONTEXT_VECTORS:
        calc_length_of_cv(term)


# @jit(target="cuda")
def calc_cosine(term1, term2, recalc=False):
    if not recalc:
        if term1 in shared.COSINES and term2 in shared.COSINES[term1]:
            # already done. Dont calculate again
            return

    term1_len = shared.CONTEXT_VECTORS_LENGTH.get(term1, None)
    term2_len = shared.CONTEXT_VECTORS_LENGTH.get(term2, None)

    if term1_len is None or term2_len is None:
        raise ValueError(f"{term1} or {term2} lengths dont exist in dict. Term might not be normalized")
    term1_cv = shared.CONTEXT_VECTORS[term1]
    term2_cv = shared.CONTEXT_VECTORS[term2]

    dot_product = 0
    for ix in range(len(term1_cv)): dot_product += term1_cv[ix] * term2_cv[ix]

    cosine = dot_product

    if term1 not in shared.COSINES:
        shared.COSINES[term1] = dict()
    if term2 not in shared.COSINES:
        shared.COSINES[term2] = dict()

    shared.COSINES[term1][term2] = cosine
    shared.COSINES[term2][term1] = cosine

    # print(term1, term2, cosine)


def calc_all_cosines_for_term(term):
    if term not in shared.COSINES:
        shared.COSINES[term] = dict()

    for term2 in shared.CONTEXT_VECTORS:
        if term2 not in shared.COSINES[term]:
            calc_cosine(term, term2)


def calc_cosines_for_all(term_list=None):
    # if not term_list: term_list = list(shared.CONTEXT_VECTORS.keys())

    for term1 in term_list:
        print("term: ", term1, end="... ")
        calc_all_cosines_for_term(term1)
        print("done")

def gen_highest_similar_terms(term, limit):
    # print("calc similar", term)
    if term not in shared.COSINES:
        raise ValueError(f"term {term} not in cosines dict")

    all_terms = list(shared.COSINES[term].keys())
    # print(all_terms)
    # utils.pretty_print_dict(shared.COSINES[term])
    all_terms.sort(key=lambda k: shared.COSINES[term][k], reverse=True)

    shared.SIMILAR_TERMS[term] = all_terms[:limit]


def gen_all_similar_terms(term_list, similar_limit=10):
    """

    :param term_list: No of terms to calculate for
    :param similar_limit: No of similar terms to find
    :return:
    """
    # if not term_list: term_list = list(shared.CONTEXT_VECTORS.keys())
    for term in term_list:
        gen_highest_similar_terms(term, similar_limit)


if __name__ == "__main__":
    start = timer()
    no_docs = 500  # if no_docs is more than total, no docs, only total will be used
    no_similar_terms = 75
    utils.map_document_ids(type="processed")
    DOC_DIR_PATH = utils.ret_document_dir_path()
    raw_names = utils.get_raw_names(shared.DOCUMENT_ID_MAP)

    # print(raw_names[0][0], raw_names[0][1])
    print("Accumulating Vectors...")
    ix = 1
    for d in raw_names[:no_docs]:
        print(str(ix) + ". file: " + d[0] + d[1] + "...", end="")
        process_document(d[0] + d[1])
        print("done")
        ix += 1

    print("All vectors accumulated")
    print()
    print("Normalizing...", end="")
    normalize_all_terms()
    print("done")
    
    #print(shared.CONTEXT_VECTORS["oromis"])
    # term_list = random.choices(population=list(shared.CONTEXT_VECTORS.keys()), k=no_similar_terms)
    term_list = list(shared.CONTEXT_VECTORS.keys())[:no_similar_terms]
    print("Calculating Cosines...", end="")
    calc_cosines_for_all(term_list)
    print("done")
    print("Finding Similar terms...", end="")
    gen_all_similar_terms(term_list)
    print("done")
    print()
    print("Displaying similar terms for " + str(no_similar_terms))
    print()
    # utils.pretty_print_dict(shared.CONTEXT_VECTORS)
    utils.pretty_print_dict(shared.SIMILAR_TERMS)

    print()
    print("Total unique terms (excluding stopwords): ", len(shared.CONTEXT_VECTORS))
    print("Total documents: ", len(raw_names[:no_docs]))

    import os
    import psutil

    process = psutil.Process(os.getpid())
    print("Total Memory Used: ", process.memory_info().rss / (1024 ** 2), "MBs")  # in bytes
    print("Total time taken: ", timer() - start, " seconds")
