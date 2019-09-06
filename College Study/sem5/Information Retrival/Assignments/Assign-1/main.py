import utils
import indexer
import shared
import retriever
import help_docs

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
    query = input()
    print()

    try:
        res = retriever.process_normal_query(query)
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
                5. Perform Wild-card queries
                6. Exit
            """
    print("What do you want to do? Enter number:\n")
    print(options)

    choice = int(input())

    if choice == 1:
        menu_create_index()
    elif choice == 2:
        menu_print_index()
    elif choice == 3:
        menu_perform_query()
    elif choice == 4:
        pass
    elif choice == 5:
        pass
    elif choice == 6:
        print("Bye :)")
        exit()

    print()            

if __name__ == "__main__":
    shared.DOCUMENT_ID_MAP = utils.map_document_ids()
    
    while True:
        menu()
