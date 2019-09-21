import constants
import graph
import shared


def build_graph():
    csv_file = open(constants.DATASET_FILE, mode="r")
    lines = csv_file.readlines()
    csv_file.close()
    split_lines = [l.strip('\n').strip(' ').split(',') for l in lines]
    # l[0] is the origin
    # l[1] is the destination
    # l[3] is the straight line distance

    node_id = 0
    for l in split_lines:
        l[0] = l[0].lower()
        l[1] = l[1].lower()

        if l[0] not in shared.GRAPH_NODES:
            graph_node = graph.Node(node_id, l[0])
            node_id += 1
            shared.GRAPH_NODES[l[0]] = graph_node

        if l[1] not in shared.GRAPH_NODES:
            graph_node = graph.Node(node_id, l[1])
            node_id += 1
            shared.GRAPH_NODES[l[1]] = graph_node

    for l in split_lines:
        l[0] = l[0].lower()
        l[1] = l[1].lower()

        node1 = shared.GRAPH_NODES[l[0]]
        node2 = shared.GRAPH_NODES[l[1]]
        node1.add_edge(node2, l[3])
        node2.add_edge(node1, l[3])


def print_action_sequence(action_seq: list):
    print("\n Action Sequence: \n")
    for a in action_seq[:len(action_seq)-1]:
        print(a.name, end= " --> ")

    print(action_seq[-1].name)

    print()

def path_finding_goal_test():
    pass
