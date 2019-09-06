import utils
import os
import re
import shared

@utils.enforce_types(str, int, return_type=None)
def insert_into_posting_list(index_key, value):
    pos = 0
    while pos < len(shared.BASE_INDEX[index_key]):

        if shared.BASE_INDEX[index_key][pos] == value:
            # Duplicate entry
            return

        if shared.BASE_INDEX[index_key][pos] > value:
            break
        
        pos+=1
    shared.BASE_INDEX[index_key].insert(pos,value)    

def create_document_index(document_id):

    document_path = os.path.join(utils.ret_document_dir_path(), shared.DOCUMENT_ID_MAP[document_id])
    doc = open(document_path)
    content = doc.read()
    doc.close()

    words = filter(None,re.split("[ \n]", content))
    # filer None removes blank strings. re.split splits on <space> and <newline> character

    for w in words:
        w = w.lower()
        w = utils.strip_useless_characters(w)
        utils.check_special_characters(w)

        if w not in shared.BASE_INDEX:
            shared.BASE_INDEX[w] = list()

        insert_into_posting_list(w,document_id)

def create_full_index():
    for key in shared.DOCUMENT_ID_MAP:
        create_document_index(key)        