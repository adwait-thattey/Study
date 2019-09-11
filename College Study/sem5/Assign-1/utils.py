import constants
import os
import shared

def enforce_types(*types, return_type=None):
    def decorator(f):
        def new_f(*args, **kwds):
            #we need to convert args into something mutable   
            for (a, t) in zip(args, types):
                if not isinstance(a,t):
                    raise TypeError(" [Enforced Types]: Arguments of wrong type passed to function")
                #feel free to have more elaborated convertion
            result = f(*args, **kwds)
            if return_type:
                if not isinstance(result,return_type):
                    raise TypeError(f" [Enforced Types]: Function returned wrong type \n Expected {repr(return_type)}. Received {type(result)} ")
            
            return result
        return new_f
    return decorator

def strip_useless_characters(word):
    for ch in constants.useless_character_list:
        word = word.strip(ch)

    return word    

def check_special_characters(word):
    for ch in constants.special_characters:
        if ch in word:
            raise ValueError(f"The words must not contain these characters: {constants.special_characters}. The word here is {word}") 

def ret_document_dir_path():
    cur_dirpath = os.getcwd()
    directory = os.path.join(cur_dirpath, constants.documents_directory_name)

    return directory

def map_document_ids():

    directory = ret_document_dir_path()
    
    document_id_map = dict()

    idx = 1

    for filename in os.listdir(directory):
        if filename.endswith(".txt"): 
            document_id_map[idx] = filename
            idx+=1
        else:
            continue

    return document_id_map

def pretty_print_dict(dict_instance):
    for key in dict_instance:
        print(key, " : ", dict_instance[key])


def print_base_index():
    pretty_print_dict(shared.BASE_INDEX)

def pretty_print_doc_result(doc_list):
    if not doc_list:
        print("No documents matched the given query")
        return    
    for doc in doc_list:
        print(doc, shared.DOCUMENT_ID_MAP[doc])

def print_btree_layer(layer):
    print("Btree layer:")
    for node in layer:
        print(str(node), end=" :")
        for pair in node.data_pointer_pairs:
            print(f"({pair.data},{str(repr(pair.pointer))})", end="  ")
        print()

if __name__ == "__main__":
    print(ret_document_dir_path())
    print(map_document_ids())        