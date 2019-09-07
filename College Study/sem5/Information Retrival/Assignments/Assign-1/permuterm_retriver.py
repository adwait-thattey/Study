import permuterm_indexer
import shared
import utils
import retriever

def append_delimiter_and_rotate(query):
    if query.count("*") != 1:
        print("There must be exactly 1 * in the query")

    query = query + "$"

    while query[-1] != "*":
        query = query[-1] + query[:len(query)-1]

    # remove * and return
    return query[:len(query) - 1]

def find_in_node(node, query):
    """
    returns a tuple (bool,list(pointer))
    the bool tells whether found (true if data full match. false otherwise)
    pointer gives direction to next node to travese
    """
    if not node:
        return (False,[])

    l = len(query)
    found = False
    pointers = list()
    prev = None
    for pair in node.data_pointer_pairs:
        if query == pair.data[:l]:
            # found node
            found = True
            break

        elif query < pair.data[:l]:
            pointers.append(pair.pointer)
            if prev and prev.pointer:
                pointers.append(prev.pointer.right_child)
            break
        
        prev = pair
            
        
        
    else:
        # loop was not broken
        # go right
        pointers.append(node.right_child)
        return(found,pointers)        


    # loop was broken
    # return
    return (found,pointers)



def find_in_tree(query):
    final_nodes = list()
    chosen_node = shared.PERMUTERM_TREE_ROOT
    
    found,next_nodes = find_in_node(chosen_node,query)

    if found:
        final_nodes.append(chosen_node)

    while len(next_nodes) > 0:
        new_nodes = list()
        for n in next_nodes:
            found,nodes = find_in_node(n,query)
            if found:
                final_nodes.append(n)
            new_nodes.extend(nodes)
        
        next_nodes = new_nodes
    return final_nodes
    # return either a valid node if found, or None if was not found

def explore_subtree(node, query):
    if not node:
        return []

    l = len(query)
    if node.data_pointer_pairs[0].pointer is None:
        # reached bottom level
        matched_words = [pair.data for pair in node.data_pointer_pairs if pair.data[:l] == query]

        return matched_words

    matched_words = []
    last_explored = False
    for pair in node.data_pointer_pairs:
        if query == pair.data[:l]:
            matched_words.extend(explore_subtree(pair.pointer, query))
            last_explored = True

        elif query < pair.data[:l]:
            if last_explored:
                matched_words.extend(explore_subtree(pair.pointer, query))
                last_explored = False
                break
    if last_explored:
        matched_words.extend(explore_subtree(node.right_child, query))

    return matched_words

def normalize_word(rotated_word):

    while rotated_word[-1] != "$":
        rotated_word = rotated_word[-1] + rotated_word[:len(rotated_word)-1]

    # remove * and return
    return rotated_word[:len(rotated_word) - 1]
    
def find_matching_words(query):
    
    query = append_delimiter_and_rotate(query)
    found_nodes = find_in_tree(query)

    if not found_nodes:
        print("No result for the query")
        return
    

    matching_words = list()
    for node in found_nodes:
        matching_words.extend(explore_subtree(node, query))

    return [normalize_word(w) for w in matching_words]

@utils.enforce_types(str,return_type=list)
def process_wildcard_query(query_string):
   
    query_words = query_string.split(' ')
    next_operator_index = 1
    
    invert_flag = False
    operator_flag = -1 # -1: no operation. 0: AND, 1: OR
    if len(query_words) < 1:
        print("Empty query")
        return []

    idx = 0

    # for first query
    if query_words[idx].upper() == "NOT":
        invert_flag = not invert_flag
        idx+=1
        next_operator_index += 1

    first_res=None
    if '*' in query_words[idx]:
                # wild card encountered
                matching_words = find_matching_words(query_words[idx])
                if len(matching_words) < 0:
                    print(f"No matching words found for {query_words[idx]}")
                else:
                    print(f"found these matching words for {query_words[idx]} : {str(matching_words)}")
                    if len(matching_words) == 1:
                        final_res = retriever.retrive_result(matching_words[0])
                    else:
                        res1 = retriever.retrive_result(matching_words[0])
                        for x in range(1,len(matching_words)):
                            res2 = retriever.retrive_result(matching_words[x])
                            res1 = retriever.perform_OR(res1,res2)
                        
                        final_res = res1    
    else:
        final_res = retriever.retrive_result(query_words[idx])
    final_result = final_res
    
    if invert_flag:
        final_result = retriever.perform_NOT(final_result)
        invert_flag = not invert_flag

    idx+=1

    while idx < len(query_words):
        if idx == next_operator_index:
            if query_words[idx].upper() == "OR":
                operator_flag = 1
            elif query_words[idx].upper() == "AND":
                operator_flag = 0
            else:
                raise ValueError("Expected AND/OR operation at this position. Received " + query_words[idx])        
            
            next_operator_index+=2
        elif query_words[idx].upper() == "NOT":
            invert_flag = not invert_flag
            next_operator_index+=1
        else:
            res = None

            if '*' in query_words[idx]:
                # wild card encountered
                matching_words = find_matching_words(query_words[idx])
                if len(matching_words) < 0:
                    print(f"No matching words found for {query_words[idx]}")
                else:
                    print(f"found these matching words for {query_words[idx]} : {str(matching_words)}")
                    if len(matching_words) == 1:
                        res = retriever.retrive_result(matching_words[0])
                    else:
                        res1 = retriever.retrive_result(matching_words[0])
                        for x in range(1,len(matching_words)):
                            res2 = retriever.retrive_result(matching_words[x])
                            res1 = retriever.perform_OR(res1,res2)
                        
                        res = res1    
            else:
                res = retriever.retrive_result(query_words[idx])
            
            if invert_flag:
                res = retriever.perform_NOT(res)
                invert_flag = not invert_flag
            
            if operator_flag > -1:
                if operator_flag == 0:
                    final_result = retriever.perform_AND(final_result, res)
                elif operator_flag == 1:
                    final_result = retriever.perform_OR(final_result, res)        

                operator_flag = -1

        idx+=1

    return final_result    
