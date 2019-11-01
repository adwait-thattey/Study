import problem2_builder
import shared
import utils
import graph
import search


def print_help_docs():
    help_docs = '''
        The *main.py* file is the main.py driver code
        *constants.py* contains some constants like dataset name
        *shared.py* contains all data that is shared by all modules like graph and heuristics
        *utils.py* contains some utility functions for pretty printing etc
        
        The main files are graph.py and search.py
        *graph.py* defines the basic structure of node and edge of graph
        *search.py* defines an algorithm for searching on the graph. 
        These both are problem independent. They define generic structure of graph and search algorithm. 
        We can define any valid problem and pass parameters to these algorithms to solve.
        
        The same methods are called for problem 1 and problem 2 by changing method parameters
        See the individual files for more details
    '''
    print(help_docs)
    exit()


def problem1():
    source = "Shimla"
    dest = "Bangalore"
    algorithm = "astar"

    utils.build_problem1_graph()
    utils.build_problem1_heuristics(dest)

    # normalize
    source = source.lower()
    dest = dest.lower()
    algorithm = algorithm.lower()

    if source not in shared.GRAPH_NODES or dest not in shared.GRAPH_NODES:
        print("\n\nSource or Destination not found in graph")
        exit()

    if algorithm == "gbfs" or algorithm == "astar":
        if dest != "bangalore":
            print(
                "\nOnly Bangalore destination is available for GBFS and ASTAR as heuristic is not available for other cities")
            exit()

    source_node = shared.GRAPH_NODES[source]

    goal_test = lambda node: node.data == dest  # goal test checks if the given node is the destination
    expander_function = lambda node: [ndp.node for ndp in node.edges]
    # expands all the children of the node. ndp stands for node_distance_pair

    # perform the actual search. Returns action sequence and iteration count


    print(
        f"Starting from {source.title()} . Going till {dest.title()}. Using {algorithm.upper()} Algorithm. \n This can be configured in main.py -> problem1 method")

    action_sequence, iter_count = search.graph_search(source_node, goal_test, expander_function,
                                                      algorithm)

    if not action_sequence:
        print("No path found")
        print(f"Took {iter_count} iterations but could not reach")
    else:
        utils.print_action_sequence(action_sequence)
        print(f"Total cost {action_sequence[-1].cumalative_distance}")
        print(f"Took {iter_count} iterations to react goal ")


def problem2():
    # The '-' represents the empty block here
    start_configuration = [
        ['1', '5', '2'],
        ['7', '4', '3'],
        ['-', '8', '6']
    ]
    end_configuration = [
        ['1', '2', '3'],
        ['4', '5', '6'],
        ['7', '8', '-']
    ]
    # This particular example is solvable by bfs and astar but not by dfs and gbfs

    algorithm = "astar"
    # normalize:
    source_rep = ["".join(i) for i in start_configuration]
    dest_rep = ["".join(i) for i in end_configuration]

    print("Start State:")
    utils.print_puzzle_configuration(source_rep)
    print("\nEnd State:")
    utils.print_puzzle_configuration(dest_rep)
    print(f"Solving using {algorithm} algorithm")
    print("This can be configured in the main.py -> problem2 method\n")

    problem2_builder.build_final_position_index(dest_rep)

    start_node = problem2_builder.build_node(source_rep)
    shared.GRAPH_NODES["".join(source_rep)] = start_node

    goal_test = lambda node: node.data == dest_rep

    def expander_function(node):
        return problem2_builder.get_neighbour_nodes(node)

    action_sequence, iter_count = search.graph_search(start_node, goal_test, expander_function,
                                                      algorithm)

    if not action_sequence:
        print("No path found")
        print(f"Took {iter_count} iterations but couldn't reach")
    else:
        print("Action Sequence: \n\n")
        ix = 0
        for node in action_sequence:
            print(f"Action {ix} :")
            ix += 1
            utils.print_puzzle_configuration(node.data)
        print(f"Took {iter_count} iterations to find goal ")
        print(f"Total cost {action_sequence[-1].cumalative_distance}")

if __name__ == "__main__":
    opening_question = '''
        What do you want to do ?
        1. Problem 1
        2. Problem 2
        3. view explanation for code
        4. exit
    
        input number
    '''

    print(opening_question)
    choice = input()
    if choice == "1":
        problem1()
    elif choice == "2":
        problem2()
    elif choice == "3":
        print_help_docs()
    elif choice == "4":
        exit()
    else:
        print("Invalid choice!")
        exit()
