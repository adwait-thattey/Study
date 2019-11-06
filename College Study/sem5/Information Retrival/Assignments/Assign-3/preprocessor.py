"""
This module separates files into smaller units each containing no more than 10k characters.
Then removes special characters and everything within brackets

"""
import os

import utils

DOC_DIR_PATH = ""


def separator(filename, ext):
    f = open(os.path.join(DOC_DIR_PATH, filename + ext), mode="r")
    contents = f.read()
    f.close()
    contents = contents.split('\n')
    char_sum = 0
    cur_file_index = 1
    start_index = 0
    for ix in range(len(contents)):
        char_sum += len(contents[ix])
        if char_sum > 5000:
            f = open(os.path.join(DOC_DIR_PATH, f"{filename}_{cur_file_index}{ext}"), mode="w")
            f.write("\n".join(contents[start_index:ix]))
            f.close()
            char_sum = len(contents[ix])
            start_index = ix
            cur_file_index += 1

    f = open(os.path.join(DOC_DIR_PATH, f"{filename}_{cur_file_index}{ext}"), mode="w")
    f.write("\n".join(contents[start_index:len(contents)]))
    f.close()


def remove_enclosed_content(line):
    bracket_pairs = (('(', ')'), ('[', ']'), ('{', '}'))

    for pair in bracket_pairs:
        opening_pos = line.find(pair[0])
        while opening_pos != -1:
            closing_pos = line.find(pair[1])
            if closing_pos == -1:
                print("Inconsistent brackets", pair)
                break
            line = line[:opening_pos] + line[closing_pos + 1:]
            opening_pos = line.find(pair[0])

    return line


def preprocess_document(doc, ext):
    print(doc)
    f = open(os.path.join(DOC_DIR_PATH, doc + ext), mode="r")
    contents = f.read()
    f.close()
    lines = contents.split('\n')
    new_lines = list()
    for l in lines:

        l = l.strip('\n').strip()
        l = remove_enclosed_content(l)
        dot_pos = l.find('.')
        start = 0
        while dot_pos != -1 and dot_pos < len(l) - 1:

            if l[dot_pos + 1] == " " or l[dot_pos + 1].isupper():
                # sentence end
                nl = l[:dot_pos + 1].strip().strip('\n')
                new_lines.append(nl)
                l = l[dot_pos + 1:]
            start = dot_pos + 1
            dot_pos = l.find('.', start)

        l = l.strip()
        new_lines.append(l)

    f = open(os.path.join(DOC_DIR_PATH, doc + ext), mode="w")
    f.write("\n".join(new_lines))
    f.close()
    del (lines)
    del (new_lines)


if __name__ == "__main__":
    doc_id_map = utils.map_document_ids()
    DOC_DIR_PATH = utils.ret_document_dir_path()
    raw_names = utils.get_raw_names(doc_id_map)
    print(raw_names)
    # print(raw_names[0][0], raw_names[0][1])
    for d in raw_names:
        preprocess_document(d[0], d[1])
