import utils
import indexer
import shared
import retriever
import help_docs
import permuterm_indexer
import permuterm_retriver

def menu_create_index():
    indexer.create_full_index()

    print("Index Created")

def menu_print_index():
    if len(shared.BASE_INDEX) <=0 :
        print("Please create index before trying to print")
        return

    utils.print_base_index()

def menu_perform_query():
    if len(shared.BASE_INDEX) <=0 :
        print("Please create index before trying queries")
        return

    print(help_docs.process_normal_query_help)
    print("Enter query: ")
    query = input().lower()
    print()

    try:
        res = retriever.process_normal_query(query)
        print("The documents satisfying given query are: ")
        utils.pretty_print_doc_result(res)
    except ValueError as ve:
        print("Incorrect Input")
        print("Error: ", str(ve))

def menu_create_permuterm_index():
    if len(shared.BASE_INDEX) <=0 :
        print("Please create index before creating permuterm index")
        return

    permuterm_indexer.build_permuterm_index_bplus_tree()
    print("Permuterm index created")

def menu_find_matching_wild_words():
    if not shared.PERMUTERM_TREE_ROOT:
        print("Please create permuterm index before using wild card queries")
        return

    print(help_docs.find_matching_words)
    print("Enter query: ")
    query = input().lower()

    print("Matching words are: ")
    print(permuterm_retriver.find_matching_words(query))

def menu_perform_wild_card_queries():
    if not shared.PERMUTERM_TREE_ROOT:
        print("Please create permuterm index before using wild card queries")
        return

    print(help_docs.process_wild_card_query)
    print("Enter query: ")
    query = input().lower()

    try:
        res = permuterm_retriver.process_wildcard_query(query)
        print("The documents satisfying given query are: ")
        utils.pretty_print_doc_result(res)
    except ValueError as ve:
        print("Incorrect Input")
        print("Error: ", str(ve))

def menu():
    options = """
                1. Create Index
                2. Print Index
                3. Perform query
                4. Create Permuterm Index
                5. Find matching wild card words
                6. Perform Wild-card queries
                7. Exit
            """
    print("What do you want to do? Enter number:\n")
    print(options)
    
    choice = input()

    if choice == '1':
        menu_create_index()
    elif choice == '2':
        menu_print_index()
    elif choice == '3':
        menu_perform_query()
    elif choice == '4':
        menu_create_permuterm_index()
    elif choice == '5':
        menu_find_matching_wild_words()
    elif choice == '6':
        menu_perform_wild_card_queries()
    elif choice == '7':
        print("Bye :)")
        exit()
    else:
        print("invalid choice!\n retry!")
    print()            

if __name__ == "__main__":
    shared.DOCUMENT_ID_MAP = utils.map_document_ids()
    
    while True:
        menu()
