import constants
import utils
from graph import Node
import shared

def remove_from_frontier(frontier, search_algorithm):

    if search_algorithm == "bfs":
        # return the first element in the list
        return frontier.pop(0)

    elif search_algorithm == "dfs":
        # return the last element in the frontier
        return frontier.pop()

    elif search_algorithm == "gbfs":

        chosen_node = min(frontier, key=lambda node: utils.get_heuristic_value(node))
        frontier.remove(chosen_node)
        return chosen_node

    elif search_algorithm == "astar":
        def get_parent_distance(node):
            for ndp in node.edges:
                if ndp.node == node.parent:
                    # print(ndp.node, ndp.distance)
                    return ndp.distance

            return constants.INF


        chosen_node = min(frontier, key=lambda node:  get_parent_distance(node) +  utils.get_heuristic_value(node))
        frontier.remove(chosen_node)
        return chosen_node

    else:
        raise ValueError("Incorrect algorithm name")


def graph_search(graph_nodes: dict, start_node: Node, goal_test, search_algorithm: str):
    """
    :param graph_nodes: A dict containing the nodes of the graph
    :param start_node: The start node
    :param goal_test: A function which takes a node as an argument and
                      returns TRUE of FALSE based on whether the node is the goal
    :param search_algorithm: A string specifying the search algorithm
                            Can be "BFS", "DFS", "GBFS", "ASTAR"
    :return: returns either the action sequence if a solution is found. Else returns None
    """
    search_algorithm = search_algorithm.lower()
    frontier = list()
    frontier.append(start_node)
    explored_set = dict()
    explored_order = list()
    steps_taken = 0
    chosen_node = Node
    while frontier:

        # this line changes depending on the algorithm
        chosen_node = remove_from_frontier(frontier, search_algorithm)
        # print(chosen_node, chosen_node.parent)
        steps_taken +=1
        print(steps_taken)
        explored_set[chosen_node] = True # mark node as explored
        explored_order.append(chosen_node)

        if goal_test(chosen_node):
            # goal found
            break

        # expand the node
        for ndp in chosen_node.edges:
            # ndp stands for node-distance-pair. See graph.py for more clarity
            if ndp.node not in explored_set and ndp.node not in frontier:
                ndp.node.parent = chosen_node
                frontier.append(ndp.node)

    else:
        # this is executed when while condition becomes false
        # thus frontier has become empty. Thus result not found.
        # return None to indicate result was not found
        return None

    # goal found. build and return action sequence
    rev_action_sequence = list()
    while chosen_node:
        rev_action_sequence.append(chosen_node)
        chosen_node = chosen_node.parent

    # reverse the array and return
    return rev_action_sequence[::-1]
