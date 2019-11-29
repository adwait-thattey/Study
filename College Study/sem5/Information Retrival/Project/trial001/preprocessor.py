"""
This module separates files into smaller units each containing no more than 10k characters.
Then removes special characters and everything within brackets

"""
import os

import utils
import shared
import constants
from unidecode import unidecode

DOC_DIR_PATH = ""


def remove_enclosed_content(line):
    # removes all content enclosed by brackets {} [] ()
    ret = ''
    skip1c = 0
    skip2c = 0
    skip3c = 0
    for i in line:
        if i == '[':
            skip1c += 1
        elif i == '(':
            skip2c += 1
        elif i == '{':
            skip3c += 1
        elif i == ']' and skip1c > 0:
            skip1c -= 1
        elif i == ')' and skip2c > 0:
            skip2c -= 1
        elif i == '}':
            skip3c -= 1
        elif skip1c == 0 and skip2c == 0 and skip3c == 0:
            ret += i

    return ret


def break_multiple_lines(line):
    lines = line.split('\n')
    ret_lines = list()
    for l in lines:
        l.strip().strip('.')
        start = 0
        ix = 0
        while ix < len(l):
            if l[ix] == '.':
                if ix == len(l) - 1 or l[ix + 1] == ' ':
                    ret_lines.append(l[start:ix])
                    start = ix + 2

            ix += 1
        else:
            ret_lines.append(l[start:-1])

    return ret_lines


def process_word(word: str):
    if word.isdigit() or not word.isalnum():
        return constants.null_word
    return word.lower()


def process_line(line):
    line = unidecode(line)
    line = line.strip().strip('.').strip()
    line = line.replace(',', '\n')
    line = line.replace(';', '\n')

    # convert 's to ' is'
    line = line.replace("'s", " is")
    # convert 'm to " am"
    line = line.replace("'m", " am")
    # convert can't to " can not "
    line = line.replace("can't", "can not")

    # convert n't to " not "
    line = line.replace("n't", " not")
    # convert " 'll" to " will "
    line = line.replace("'ll", " will")

    line = "".join([c if c not in constants.replaceable_special_characters else ' ' for c in line])
    line = line.replace("  ", " ")  # remove duplicate spaces

    words = [process_word(w) for w in line.split()]

    return " ".join(words)


def break_documents(lines):
    ret_docs = list()
    char_count = 0
    cur_list = list()
    for l in lines:
        char_count += len(l)
        cur_list.append(l)

        if char_count >= constants.DOCUMENT_LENGTH_LIMIT:
            ret_docs.append(cur_list)
            cur_list = list()
            char_count = 0

    ret_docs.append(cur_list)
    return ret_docs


def preprocess_document(doc, ext, prepend_name=""):
    # print(doc)

    f = open(os.path.join(constants.original_documents_directory_path, doc + ext), mode="r")
    lines = f.readlines()
    f.close()
    all_lines = list()
    [all_lines.extend(break_multiple_lines(l)) for l in lines]
    all_lines = [process_line(l) for l in all_lines]
    all_lines = [l for l in all_lines if l]  # remove null lines

    split_docs = break_documents(all_lines)
    # print(split_docs)
    idx = 1
    for split_doc in split_docs:
        f = open(os.path.join(constants.parsed_documents_directory_path, f"{prepend_name}{doc}_{idx}" + ext), mode="w")
        f.write('\n'.join(split_doc))
        f.close()
        idx += 1


if __name__ == "__main__":
    utils.map_document_ids()
    raw_names = utils.get_raw_names(shared.DOCUMENT_ID_MAP)
    print(raw_names)

    for rn in raw_names:
        print(f"Processsing {rn[0]}{rn[1]} ...", end=" ")
        preprocess_document(rn[0], rn[1])
        print("done")
    # preprocess_document("part_3", ".txt")
