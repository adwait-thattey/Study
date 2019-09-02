import random
import socket
import constants
import threading
import time

PRIVILEGED_NODES = list()
OPENED_SOCKET = None

class CentralDaemon(threading.Thread):
    def __init__(self):
        """
        """

        super().__init__()

        # self.privileged_nodes = list()
        self.received_privilege_count = 0
        self.node_privileges = dict()
        self.no_privilege_chance = 0

    def run(self):
        while self.no_privilege_chance < 3:
            self.loop()

        print(f"[CD]: Spanning tree reached in {self.received_privilege_count} privileges")

    def receive_status_from_node(self, node):
        self.node_privileges[node] = node.privilege 
        print(f"[CD]: Received status from node {node.id}")
        print(f"[CD]: {self.node_privileges}")

    def choose_privilege_node(self):
        privileged_nodes = list()
        for key, value in self.node_privileges.items():
            if value >= 0:
                privileged_nodes.append(key)

        if len(privileged_nodes) > 0:
            self.no_privilege_chance = 0
            return random.choice(privileged_nodes)
        else:
            print("[CD]: No node has privilege")
            time.sleep(1)
            self.no_privilege_chance += 1
            return None

    def grant_privilege_to_node(self):
        chosen_node = self.choose_privilege_node()
        self.reset_privileges()
        if chosen_node:
            self.received_privilege_count += 1
            print(f"[CD]: Granting privilege to {repr(chosen_node)}")
            chosen_node.change_privilege_to_true()

    def reset_privileges(self):
        self.node_privileges = dict()

    def loop(self):
        print("\n\n")
        time.sleep(1)
        self.grant_privilege_to_node()