"""
This file defines basic search algorithm for searching for a node on graph
"""

import constants
import utils
from graph import Node
import shared


def remove_from_frontier(frontier, search_algorithm):
    """
    This is the only statement in the search algorithm which changes based on the type of algorithm to be applied.
    This defines different mechanisms to remove node from frontier based on required algorithm
    :param frontier: The dataset where all next nodes are stored
    :param search_algorithm: The algorithm to be used
    :return: A node from the frontier based on search algo used
    """
    if search_algorithm == "bfs":
        # Breadth First Search FIFO
        # return the first element in the list
        return frontier.pop(0)

    elif search_algorithm == "dfs":
        # Depth First Search - Lifo
        # return the last element in the frontier
        chosen_node = frontier.pop()

        # since only last node is chosen. Empty the frontier
        frontier.clear()

        return chosen_node

    elif search_algorithm == "gbfs":
        # Greedy Best First Search

        # get the node with minimum heuristic value
        chosen_node = min(frontier, key=lambda node: utils.get_heuristic_value(node))

        # since only one is selected. clear the frontier
        frontier.clear()

        return chosen_node

    elif search_algorithm == "astar":

        def get_distance(node):
            # A function that returns g(x). Distance from current node to any child
            for ndp in node.edges:
                if ndp.node == node.parent:
                    # print(ndp.node, ndp.distance)
                    return ndp.distance

            return constants.INF

        # choose the node with lowest g(x) + h(x) value. h(x) is the heuristic
        chosen_node = min(frontier, key=lambda node: get_distance(node) + utils.get_heuristic_value(node))
        frontier.remove(chosen_node)
        return chosen_node

    else:
        raise ValueError("Incorrect algorithm name")


def graph_search(start_node: Node, goal_test, expander_function, search_algorithm: str):
    """
    :param expander_function: A function which takes a node and gives all neighbours
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
    iter_count = 0
    chosen_node = Node
    while frontier:

        # this line changes depending on the algorithm
        chosen_node = remove_from_frontier(frontier, search_algorithm)

        # print(chosen_node, chosen_node.parent)
        iter_count += 1
        explored_set[chosen_node] = True  # mark node as explored
        explored_order.append(chosen_node)

        if goal_test(chosen_node):
            # goal found
            break

        # expand the node
        next_nodes = expander_function(chosen_node)
        for n in next_nodes:
            if n not in explored_set and n not in frontier:
                n.parent = chosen_node
                frontier.append(n)



    else:
        # this is executed when while condition becomes false
        # thus frontier has become empty. Thus result not found.
        # return None to indicate result was not found
        return None, iter_count

    # goal found. build and return action sequence
    rev_action_sequence = list()
    while chosen_node:
        rev_action_sequence.append(chosen_node)
        chosen_node = chosen_node.parent

    # reverse the array and return
    return rev_action_sequence[::-1], iter_count
