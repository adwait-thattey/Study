import threading
import node
import socket
import time

class RunNode(threading.Thread):
    def __init__(self, node_id, port, level, neighbours, parent=None):
        """
        @param neighbours: a list of tuples where each tuple contains 3 elements. Id of neighbour, port of neighbour and level of neighbour
        """
        super().__init__()
        
        print(f"[Node {node_id}]: {self.getName()}")
        self.node = node.Node(node_id,port)
        self.node.level = level

        for n in neighbours:
            self.node.add_neighbour(*n)

        self.node.parent = parent        
        self.node.pick_parent()

    def run(self):

        print(self.node)
        # print("Neighbours:")
        # self.node.print_neighbours()
        self.node.refresh_privilege()
        self.node.loop()
        self.teardown()

    def teardown(self):
        pass
