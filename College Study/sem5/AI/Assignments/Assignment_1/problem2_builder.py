"""
        Representation of each node is going to be:
            ["123","456","78-"]
            ' - ' represents the empty block that can be moved
            The above given state is the final goal state

        ' - ' can be moved in 4 directions. Up, left, down and right
        I am defining moving down and right as going 'forward'
        and moving up and left as going backward

        There are 2 functions defined, get_forward_nodes and get_backward_nodes
        For each given node, these functions give their forward and backward next nodes respectively
"""
import constants
import utils
import shared
import graph


def get_row_and_col_num(node_rep: list):
    """
    returns the row and col number of the '-'
    :param node_rep:
    :return:
    """
    row_number = -1
    col_number = -1
    for ix in range(len(node_rep)):
        if '-' in node_rep[ix]:
            row_number = ix
            break

    if row_number == -1:
        raise ValueError("- not in representation. Incorrect representation")

    col_number = node_rep[row_number].find('-')

    return (row_number, col_number)


def get_neighbour_nodes_reps(node_rep: list):
    """

    :param node_rep: This is of the type ["123","456","78-"]
    :return: returns neighbour nodes.
    """
    neighbour_nodes = []
    row_num, col_num = get_row_and_col_num(node_rep)

    if row_num < constants.NO_ROWS - 1:
        new_node = node_rep.copy()

        # swap
        temp1 = new_node[row_num][col_num]
        new_node[row_num] = utils.replace_string_character(new_node[row_num], pos=col_num,
                                                           new_char=new_node[row_num + 1][col_num])
        new_node[row_num + 1] = utils.replace_string_character(new_node[row_num + 1], pos=col_num, new_char=temp1)

        neighbour_nodes.append(new_node)

    if col_num < constants.NO_COLS - 1:
        new_node = node_rep.copy()
        temp1 = new_node[row_num][col_num]
        new_node[row_num] = utils.replace_string_character(new_node[row_num], pos=col_num,
                                                           new_char=new_node[row_num][col_num + 1])
        new_node[row_num] = utils.replace_string_character(new_node[row_num], pos=col_num + 1, new_char=temp1)

        neighbour_nodes.append(new_node)

    if row_num > 0:
        new_node = node_rep.copy()

        # swap
        temp1 = new_node[row_num][col_num]
        new_node[row_num] = utils.replace_string_character(new_node[row_num], pos=col_num,
                                                           new_char=new_node[row_num - 1][col_num])
        new_node[row_num - 1] = utils.replace_string_character(new_node[row_num - 1], pos=col_num, new_char=temp1)

        neighbour_nodes.append(new_node)

    if col_num > 0:
        new_node = node_rep.copy()
        temp1 = new_node[row_num][col_num]
        new_node[row_num] = utils.replace_string_character(new_node[row_num], pos=col_num,
                                                           new_char=new_node[row_num][col_num - 1])
        new_node[row_num] = utils.replace_string_character(new_node[row_num], pos=col_num - 1, new_char=temp1)

        neighbour_nodes.append(new_node)

    return neighbour_nodes


def get_heuristic(node_rep):
    """

    :param node_rep: list of the for ["123", "456", "78-"]
    :return: an integer representing the heuristic of the node
    """
    total_heuristic = 0

    for rix in range(len(node_rep)):
        for cix in range(len(node_rep[rix])):
            char = node_rep[rix][cix]
            row_dist = abs(shared.FINAL_STATE_POS[char][0] - rix)
            col_dist = abs(shared.FINAL_STATE_POS[char][1] - cix)

            total_heuristic += row_dist + col_dist

    return total_heuristic


def build_node(node_rep):
    string_rep = "".join(node_rep)
    new_node = graph.Node(shared.NODE_ID, node_rep)
    shared.NODE_ID += 1
    shared.GRAPH_NODES[string_rep] = new_node
    shared.HEURISTIC[new_node] = get_heuristic(node_rep)

    return new_node


def get_neighbour_nodes(node: graph.Node):
    neighbour_nodes = list()
    node_rep = node.data

    neighbour_reps = get_neighbour_nodes_reps(node_rep)

    for nr in neighbour_reps:
        string_rep = "".join(nr)
        if string_rep in shared.GRAPH_NODES:
            found_node = shared.GRAPH_NODES[string_rep]

            edges = [ndp.node for ndp in node.edges]
            if found_node not in edges:
                node.add_edge(found_node, 1)
                found_node.add_edge(node, 1)
            neighbour_nodes.append(found_node)

        else:

            new_node = build_node(nr)
            node.add_edge(new_node, 1)
            new_node.add_edge(node, 1)
            # print(node, new_node)

            neighbour_nodes.append(new_node)

    return neighbour_nodes


def build_final_position_index(final_state_rep):
    for rix in range(len(final_state_rep)):
        for cix in range(len(final_state_rep[rix])):
            shared.FINAL_STATE_POS[final_state_rep[rix][cix]] = (rix, cix)


if __name__ == "__main__":
    print(get_neighbour_nodes_reps(['123', '4-6', '789']))
    # print(get_heuristic(['12-', '456', '78']))
    # print(get_heuristic(['123', '4-6', '78']))
    # print(get_heuristic(['-23', '456', '78-']))
    # print(get_heuristic(['123', '45-', '789']))
