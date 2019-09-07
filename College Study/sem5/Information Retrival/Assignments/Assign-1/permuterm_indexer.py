import indexer
import shared
import bptree
import utils
import constants

def rotate_word(word):
    if word[-1] != "$":
        word = word + "$"

    rotations = list()
    rotations.append(word)

    n = len(word)
    for i in range(1,n):
        rotations.append(word[n-i:] + word[:n-i])

    return rotations

def generate_permuterm_word_list():
    word_list = list(shared.BASE_INDEX.keys())
    shared.PERMUTERM_WORD_LIST = list()
    for word in word_list:
        shared.PERMUTERM_WORD_LIST.extend(rotate_word(word))

    shared.PERMUTERM_WORD_LIST.sort()

def split_index_to_bptree_nodes():
    """
    This will create the bottom layer of the B+ Tree
    """
    node_list = list()
    i=0
    while i < len(shared.PERMUTERM_WORD_LIST):
        node = bptree.Node(shared.NODE_IDS_ALLOTED + 1)
        shared.NODE_IDS_ALLOTED += 1
        for j in range(constants.btree_node_size):
            if (i+j)>=len(shared.PERMUTERM_WORD_LIST):
                break
            
            node.add_data_pointer_pair(shared.PERMUTERM_WORD_LIST[i+j], None)
        
        node_list.append(node)
        
        i+=constants.btree_node_size
    return node_list

def build_new_layer(current_layer):
        
    new_layer = list()
    
    if(len(current_layer) == 1):
        return current_layer

    i=0
    while i < len(current_layer):
        node = bptree.Node(shared.NODE_IDS_ALLOTED + 1)
        shared.NODE_IDS_ALLOTED += 1
        
        for j in range(constants.btree_node_size):
            if (i+j)>= len(current_layer):
                break

            node.add_data_pointer_pair(current_layer[i+j].data_pointer_pairs[-1].data, current_layer[i+j])

        i+=constants.btree_node_size

        if i < len(current_layer):
            node.right_child = current_layer[i]
            i+=1

        new_layer.append(node)

    return new_layer

def build_permuterm_index_bplus_tree():
    generate_permuterm_word_list()
    
    layer = split_index_to_bptree_nodes()
    print("\n")
    utils.print_btree_layer(layer)
    while len(layer) > 1:
        print()
        layer = build_new_layer(layer)
        print("\n")
        utils.print_btree_layer(layer)
    shared.PERMUTERM_TREE_ROOT = layer[0]

if __name__ == "__main__":
    print(rotate_word(input()))        
