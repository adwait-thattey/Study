import os
import random
import constants
import shared
import utils

if __name__ == "__main__":

    files_list = os.listdir(constants.DOCUMENT_DIR)

    word_doc_freq, word_freq = utils.get_word_freq(files_list)
    if '' in word_doc_freq:
        del word_doc_freq['']
        del word_freq['']
    top_20_freq = [i for i, j in sorted(word_freq.items(), key=lambda kv: (kv[1], kv[0]), reverse=True)][:20]
    least_20_freq = [i for i, j in sorted(word_freq.items(), key=lambda kv: (kv[1], kv[0]))][:20]
    print('most frequent words:', top_20_freq)
    print()
    print('least frequent words:', least_20_freq)

    query = utils.gen_qeury(top_20_freq, least_20_freq)

    print(query)
    inp = input("Enter choice: \
                \n0 for Raw-TF \
                \n1 for Log-TF \
                \n2 for Binary-TF \
                \n3 for Augmented-TF \
                \n4 for Okapi-TF:\n")

    if inp != '3':
        print(utils.termfreq(query, word_doc_freq, files_list, int(inp)))
    elif inp == '3':
        th = float(input("Enter threshold: "))
        print(utils.termfreq(query, word_doc_freq, files_list, 3, th))
    else:
        print('please check the input')
