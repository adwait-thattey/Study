import random
import constants
import socket
import time

class Node:
   

    def __init__(self, unique_id, central_daemon):
        """
        @param sock: of type socket
        """
        self.id = unique_id
        self.neighbours = list()
        self.parent = None
        self.level = None
        self.central_daemon = central_daemon
        self.old_privilege = -1
        self.privilege = -1
        self.total_nodes = constants.TOTAL_NODES
        self.privilege_granted = False
        self.message_dict = dict()

    def __repr__(self):
        return f"<node {self.id}>"    

    def __str__(self):
        return str(self.id) + " level:" + str(self.level) + " parent:" + repr(self.parent)
    

    def print_neighbours(self):
        for node in self.neighbours:
            print(node)

    def add_neighbours(self,neighbours):
        self.neighbours.extend(neighbours)

    def pick_parent(self):
        if self.parent is None:
            
            parent_choice = random.choice(self.neighbours)
            
            # while parent_choice.parent == self:
            #     parent_choice.pick_parent()
            #     parent_choice = random.choice(self.neighbours)

            self.parent = parent_choice

        elif isinstance(self.parent,str):
            for neigh in self.neighbours:
                if neigh.id == self.parent:
                    self.parent = neigh
                    break

    def check_privilege(self):
        # see neighbours and check if the node has privilege. If yes, send a message to daemon that node has privilege
        if (self.level > self.total_nodes):
            self.level = self.total_nodes

        if self.level < self.total_nodes:
            if self.level == self.parent.level + 1:
                # node is legit
                self.privilege = -1
                return
            else:
                if self.parent.level < self.total_nodes:
                    # Rule 0
                    # parent is correct. fix yourself
                    self.privilege = 0

                    # fix rightaway
                    self.level = self.parent.level + 1


                    return
                elif self.parent.level == self.total_nodes:
                    # Rule 1
                    # Parent is illegitimate. Make level same as parent
                    self.privilege = 1
                    return 
                else:
                    # parent.level > total_nodes
                    # send parent message to fix self
                    self.privilege = -2
        else:
            # self level is total_nodes
            # check if any of the neighbours have legit level. If yes, make them parent
            # rule 2
            for n in self.neighbours:
                if n.level < self.total_nodes - 1:
                    self.privilege = 2
                    break

    def notify_central_daemon_of_privilege(self):
        if self.privilege != self.old_privilege:
            self.central_daemon.receive_status_from_node(self)

            if self.central_daemon.current_round in self.message_dict:
                self.message_dict[self.central_daemon.current_round] += 1
            else:
                self.message_dict[self.central_daemon.current_round] = 1

            # print(f"[NODE {self.id}]: Message {self.message_list} ")


    def use_privilege(self):
        self.privilege_granted = False
        # self.message_list.append(0)
        print(f"[NODE {self.id}]: Appended to message list ")


        if self.privilege < 0:
            return

        elif self.privilege == 0:
            self.level = self.parent.level + 1

        elif self.privilege == 1:
            self.level = self.total_nodes

        elif self.privilege == 2:
            for n in self.neighbours:
                if n.level < self.total_nodes - 1 and n.parent != self:
                    self.level = n.level + 1
                    self.parent = n
                    break

        print(f"[NODE {self.id}]: Privilege {self.privilege} Action Completed. Broadcasting. ")
        self.refresh_privilege()
        self.broadcast_change_to_neighbours()

    def receive_update_from_neighbour(self, sender_node, code):
        """
        @param code: code=1 signifies neighbour has updated level. should refresh privilege
        """
        print(f"[NODE {self.id}]: Received update code {code} from {repr(sender_node)} ")
        if code == 1:
            # self.message_list.append(0)
            self.refresh_privilege()

    def broadcast_change_to_neighbours(self):
        for n in self.neighbours:
            n.receive_update_from_neighbour(self, code=1)
            if self.central_daemon.current_round in self.message_dict:
                self.message_dict[self.central_daemon.current_round] += 1
            else:
                self.message_dict[self.central_daemon.current_round] = 1
            # print(f"[NODE {self.id}]: Message {self.message_list} ")

    def refresh_privilege(self):
        # time.sleep(1)
        fix_flag = False
        if self.parent:
            self.check_privilege()
            print(f"[NODE {self.id}]: Privilege Refreshed {self.privilege}")
            if self.privilege == 0:
                # already fixed
                fix_flag = True
            else:    
                            
                self.notify_central_daemon_of_privilege()
                self.old_privilege = self.privilege
        else:

            print(f"[NODE {self.id}]: Privilege Not refreshed {self.privilege}")

        if fix_flag:
            # was fixed. refresh again
            self.refresh_privilege()

    def change_privilege_to_true(self):
        self.privilege_granted = True

    def handle_rcv_data(self,addr,data):            
        decoded_data = data.decode()
        print(f"[Node {self.id}]: received data", decoded_data)
        
        if addr == constants.CENTRAL_DAEMON_PORT:
            # message from central daemon
            if decoded_data == "privilege":
                print(f"[NODE {self.id}]: got privilege")
                pass
        else:
            # messsage from neighbour
            split_message = decoded_data.split(' ')
            nid = split_message[0]
            nlevel = int(split_message[1])
            for n in self.neighbours:
                if n.id == nid:
                    n.level = nlevel
                    break

            self.refresh_privilege()
                        

    def loop(self):
        print(f"[Node {self.id}]: In loop")