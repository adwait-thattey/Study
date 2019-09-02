import threading
import node
import socket
import time

class RunNode(threading.Thread):
    def __init__(self, node_id, level, central_daemon):
        """
        @param neighbours: a list of tuples where each tuple contains 3 elements. Id of neighbour, port of neighbour and level of neighbour
        """
        super().__init__()
        
        
        self.node = node.Node(node_id,central_daemon)
        self.node.level = level
        self.keep_running = True

    def add_neighbours(self, neighbours):
        self.node.add_neighbours(neighbours)

    def set_parent(self, parent):
        self.node.parent = parent

    def set_random_parent(self):
        self.node.pick_parent()        

    def run(self):

        print(self.node)
        # print("Neighbours:")
        # self.node.print_neighbours()
        self.node.refresh_privilege()

        while self.keep_running:
            self.loop()

        print(f"[THREAD {self.node.id}]: Shutting Down")    
        self.teardown()

    def teardown(self):
        pass

    def loop(self):
        # time.sleep(0.1)
        # print(f"[THREAD {self.node.id}]: PG {self.node.privilege_granted}")
        if self.node.privilege_granted:
            self.node.use_privilege()    