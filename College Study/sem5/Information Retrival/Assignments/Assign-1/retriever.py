import utils
import shared

def retrive_result(word):
    if word in shared.BASE_INDEX:
        return shared.BASE_INDEX[word]

    return []    

@utils.enforce_types(list,list, return_type=list)
def perform_OR(result1, result2):
    i=0
    j=0
    merged_result = list()
    while (i < len(result1)) and ( j < len(result2) ):
        
        if result1[i] < result2[j]:
            merged_result.append(result1[i])
            i+=1
        elif result1[i] == result2[j]:
            # remove duplicate entries
            # The assumption here is that both lists don't contain duplicates
            merged_result.append(result1[i])
            i+=1
            j+=1
            
        else:
            merged_result.append(result2[j])
            j+=1

    merged_result.extend(result1[i:])
    merged_result.extend(result2[j:])

    return merged_result

@utils.enforce_types(list,list, return_type=list)
def perform_AND(result1, result2):
    i=0
    j=0
    merged_result = list()
    while (i < len(result1)) and ( j < len(result2) ):
        
        if result1[i] < result2[j]:
            i+=1
        elif result1[i] == result2[j]:
            # only keep duplicate entries
            # The assumption here is that both lists don't contain duplicates
            merged_result.append(result1[i])
            i+=1
            j+=1
            
        else:
            j+=1


    return merged_result

@utils.enforce_types(list, return_type=list)
def perform_NOT(result):
    doc_ids = shared.DOCUMENT_ID_MAP.keys()
    # print(doc_ids)
    inverted_result = [k for k in doc_ids if k not in result]

    return inverted_result

@utils.enforce_types(str,return_type=list)
def process_normal_query(query_string):
    """
    The query can be something like:
    word1 AND word2 OR word2
    Evaluation is from left to right.
    This will return all documents which either contain both word1 and word2 or simple contain word3
    Put NOT before the word to invert
    Example: word1 AND NOT word2
    """
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

    final_result = retrive_result(query_words[idx])
    if invert_flag:
        final_result = perform_NOT(final_result)
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
            # normal word
            res = retrive_result(query_words[idx])
            if invert_flag:
                res = perform_NOT(res)
                invert_flag = not invert_flag
            
            if operator_flag > -1:
                if operator_flag == 0:
                    final_result = perform_AND(final_result, res)
                elif operator_flag == 1:
                    final_result = perform_OR(final_result, res)        

                operator_flag = -1

        idx+=1

    return final_result    

if __name__ == "__main__":
    l1 = [1,6,9, 11, 13]
    l2 = [2,5,7,9,10, 13]
    shared.DOCUMENT_ID_MAP = utils.map_document_ids()
    print(perform_NOT(l1))