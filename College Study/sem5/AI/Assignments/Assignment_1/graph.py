"""
This module defines the structure of node and edge
"""


class Node:
    """
    Structure of node
    """
    class NodeDistancePair:
        """
            A pair of neighbour node and distance. This forms and edge
        """
        def __init__(self, node, distance: float):
            self.node = node
            self.distance = distance

        def __repr__(self):
            return f"<{self.node.name}:{self.distance}>"

    def __repr__(self):
        return f"<node {self.id}>"

    def __str__(self):
        return f"<node {self.id}-{self.data}>"

    def __init__(self, node_id, node_data):
        self.id = node_id
        self.data = node_data
        self.edges = list()
        self.parent = None  # will be updated in real time by the algorithm
        self.cumalative_distance = 0

    def add_edge(self, node, distance):
        if not isinstance(node, Node):
            raise TypeError("Argument must be of type Node")

        node_pair = self.NodeDistancePair(node, distance)

        self.edges.append(node_pair)


def print_graph(graph_nodes):
    for key in graph_nodes:
        print(graph_nodes[key], " : ", graph_nodes[key].edges)
