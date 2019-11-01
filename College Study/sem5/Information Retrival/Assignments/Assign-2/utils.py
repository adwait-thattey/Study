import random
import re

from math import log10
import shared


def pre_process(terms):
    parsed_words = set()
    for word in terms:
        word = word.lower()
        word = re.sub("[^0-9a-zA-Z-]+", "", word)
        if word in shared.STOP_WORDS:
            continue
        parsed_words.add(word)
    return parsed_words


def get_word_freq(files_list):
    word_doc_freq = dict()
    word_freq = dict()
    for file in files_list:
        f = open('documents/' + file, 'r')
        words = f.read().split()
        words = pre_process(words)
        for word in words:
            if word in word_freq:
                word_doc_freq[word][file] = word_doc_freq[word].get(file, 0) + 1
            else:
                word_doc_freq[word] = {file: 1}
            word_freq[word] = word_freq.get(word, 0) + 1
    return word_doc_freq, word_freq


def raw_tf(query, word_doc_freq, docs):
    terms = dict()
    print("Raw TF")
    j = 0
    while j < len(docs):
        score = 0
        for word in query:
            if word in word_doc_freq:
                if docs[j] in word_doc_freq[word]:
                    score += word_doc_freq[word][docs[j]]
        terms[docs[j]] = [docs[j], score]
        j += 1

    return terms


def log_tf(query, word_doc_freq, docs):
    terms = dict()
    print("By Log-TF")
    for i in docs:
        score = 0
        for word in query:
            if word in word_doc_freq:
                if i in word_doc_freq[word]:
                    score += log10(1 + word_doc_freq[word][i])
        terms[i] = [i, score]

    return terms


def bin_tf(query, word_doc_freq, docs):
    terms = dict()
    for i in docs:
        score = 0
        for word in query:
            if word in word_doc_freq:
                if i in word_doc_freq[word]:
                    score += 1
            terms[i] = [i, score]

    return terms


def aug_tf(query, word_doc_freq, docs, threshold):
    terms = dict()
    print("By Augmented-TF")
    for i in docs:
        score = 0
        for word in query:
            if word in word_doc_freq:
                if i in word_doc_freq[word]:
                    mx = max([dc.get(i, 0) for dc in word_doc_freq.values()])
                    score += threshold + (1 - threshold) * word_doc_freq[word][i] / mx

        terms[i] = [i, score]

    return terms


def okapi_tf(query, word_doc_freq, docs):
    terms = dict()
    print("By Okapi-TF")
    for i in docs:
        score = 0
        for word in query:
            if word in word_doc_freq:
                if i in word_doc_freq[word]:
                    tf = word_doc_freq[word][i]
                    score += tf / (2 + tf)
        terms[i] = [i, score]

    return terms


def print_ranking(ranking):
    print("Ranking of documents ")

    for r in ranking:
        print(r)


def termfreq(query, word_doc_freq, docs, choice=0, th=0):
    terms = dict()
    if choice == 0:
        terms = raw_tf(query, word_doc_freq, docs)

    elif choice == 1:
        terms = log_tf(query, word_doc_freq, docs)

    elif choice == 2:
        terms = bin_tf(query, word_doc_freq, docs)

    elif choice == 3:
        terms = aug_tf(query, word_doc_freq, docs, th)

    elif choice == 4:
        terms = okapi_tf(query, word_doc_freq, docs)

    final_ranking = [(i, j[-1]) for i, j in sorted(terms.items(), key=lambda kv: (kv[1][-1], kv[0]), reverse=True)]
    print_ranking(final_ranking)


def gen_qeury(top_20_freq, least_20_freq):
    query = []
    i1 = random.randint(0, len(top_20_freq) - 1)
    i2 = random.randint(0, min(len(top_20_freq), len(least_20_freq)) - 1)
    i3 = random.randint(0, len(least_20_freq) - 1)
    sel_list = random.randint(0, 1)
    if sel_list == 0:
        query.append(top_20_freq[i1])
        query.append(top_20_freq[i2])
        query.append(least_20_freq[i3])
    else:
        query.append(top_20_freq[i1])
        query.append(least_20_freq[i2])
        query.append(least_20_freq[i3])
    return query
