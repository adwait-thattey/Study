class Node:
    class NodeDistancePair:
        def __init__(self, node, distance: int):
            self.node = node
            self.distance = distance

        def __repr__(self):
            return f"<{self.node.name}:{self.distance}>"

    def __repr__(self):
        return f"<node {self.id}>"

    def __str__(self):
        return f"<node {self.id}-{self.name}>"

    def __init__(self, node_id, node_name):
        self.id = node_id
        self.name = node_name
        self.edges = list()
        self.parent = None  # will be updated in real time by the algorithm

    def add_edge(self, node, distance):
        if not isinstance(node, Node):
            raise TypeError("Argument must be of type Node")

        node_pair = self.NodeDistancePair(node, distance)

        self.edges.append(node_pair)


def print_graph(graph_nodes):
    for key in graph_nodes:
        print(graph_nodes[key], " : ", graph_nodes[key].edges)
