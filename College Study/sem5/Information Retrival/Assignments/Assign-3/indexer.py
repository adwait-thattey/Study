import math
import os
import random

import constants
import utils
import shared


def gen_seed_for_term(term):
    sum = 0
    for ix in range(len(term)):
        asc_val = ord(term[ix])
        sum += (ix + 1) * asc_val

    return int(id(term))


def make_index_vector(term):
    if term in shared.INDEX_VECTORS:
        return

    shared.INDEX_VECTORS[term] = [0] * constants.VECTOR_SIZE
    to_be_replaced = math.ceil(0.05 * constants.VECTOR_SIZE)
    random.seed(gen_seed_for_term(term))

    for _ in range(to_be_replaced):
        shared.INDEX_VECTORS[term][random.randint(0, constants.VECTOR_SIZE - 1)] = random.choice([1, -1])

    return


def get_normalized_line(line):
    line = line.strip('\n').strip().strip('.')
    line = line.split(' ')
    for ix in range(len(line)):
        split_words = line[ix].split('-')
        if split_words:
            line.pop(ix)
            for s in split_words[::-1]:
                line.insert(ix, s)
            ix -= 1
            continue
        line[ix] = utils.strip_useless_characters(line[ix])

        if line[ix][-2:] == "'s":
            line[ix] = line[ix][:-2]
            # line.pop(ix)
            # print(line)
        line[ix] = line[ix].lower()
    line = [w for w in line if w not in shared.STOP_WORDS]
    return line


def make_initial_context_vector_for_line(line_list):
    for term in line_list:
        if term not in shared.CONTEXT_VECTORS:
            make_index_vector(term)
            shared.CONTEXT_VECTORS[term] = shared.INDEX_VECTORS[term].copy()


def add_iv_to_cv(term1, term2, weight):
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

    f = open(os.path.join(constants.documents_directory_name, doc), mode="r")
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


def calc_length_of_all_terms():
    for term in shared.CONTEXT_VECTORS:
        calc_length_of_cv(term)


def calc_cosine(term1, term2):
    term1_cv = shared.CONTEXT_VECTORS[term1]
    term2_cv = shared.CONTEXT_VECTORS[term2]
    term1_len = shared.CONTEXT_VECTORS_LENGTH.get(term1, None)
    term2_len = shared.CONTEXT_VECTORS_LENGTH.get(term2, None)

    if not (term1_len and term2_len):
        raise ValueError(f"{term1} or {term2} lengths dont exist in dict")

    dot_product = 0
    for ix in range(len(term1_cv)): dot_product += term1_cv[ix] * term2_cv[ix]

    cosine = dot_product / (term1_len * term2_len)

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


def calc_cosines_for_all():
    term_set = list(shared.CONTEXT_VECTORS.keys())
    for term1 in term_set:
        calc_all_cosines_for_term(term1)


def gen_highest_similar_terms(term, limit):
    # print("calc similar", term)
    if term not in shared.COSINES:
        raise ValueError(f"term {term} not in cosines dict")

    all_terms = list(shared.COSINES[term].keys())
    # print(all_terms)
    # utils.pretty_print_dict(shared.COSINES[term])
    all_terms.sort(key=lambda k: shared.COSINES[term][k], reverse=True)

    shared.SIMILAR_TERMS[term] = all_terms[:limit]


if __name__ == "__main__":
    doc_id_map = utils.map_document_ids()
    DOC_DIR_PATH = utils.ret_document_dir_path()
    raw_names = utils.get_raw_names(doc_id_map)
    # print(raw_names)
    # print(raw_names[0][0], raw_names[0][1])
    for d in raw_names:
        process_document(d[0] + d[1])

    # utils.pretty_print_dict(shared.INDEX_VECTORS)
    # print("----------")
    # utils.pretty_print_dict(shared.CONTEXT_VECTORS)
    calc_length_of_all_terms()
    # for key1 in list(shared.INDEX_VECTORS.keys()):
    #     for key2 in list(shared.INDEX_VECTORS.keys()):
    #         if key1 != key2 and shared.INDEX_VECTORS[key1] == shared.INDEX_VECTORS[key2]:
    #             print("duplicate_found", key1, key2)
    #             print("seed1", gen_seed_for_term(key1))
    #             print("seed2", gen_seed_for_term(key2))

    for term in list(shared.CONTEXT_VECTORS.keys())[:10]:
        calc_all_cosines_for_term(term)
        gen_highest_similar_terms(term, constants.SIMILAR_TERMS_LIMIT)

    print(len(shared.INDEX_VECTORS))
    utils.pretty_print_dict(shared.SIMILAR_TERMS)
