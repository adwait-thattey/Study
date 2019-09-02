import random
import constants
import socket

class Node:
    
    class Neighbour:
        def __init__(self,neighbour_id, neighbour_port, neighbour_level):
            self.id = neighbour_id
            self.port = neighbour_port
            self.level = neighbour_level

        def __str__(self):
            return str(self.id) + " port:" + str(self.port) + " level:" + str(self.level)  

    def __init__(self, unique_id, port):
        """
        @param sock: of type socket
        """
        self.id = unique_id
        self.port=port
        self.neighbours = list()
        self.parent = None
        self.level = None
        self.sock = None

        # self.sock.listen()

        # privilege of -1 indicates node is legitimate. 
        # 0 will suggest rule 0 can be applied, 1 means rule 1 can be applied
        # 2 means rule 2 can be applied
        self.privilege = -1
        self.total_nodes = constants.TOTAL_NODES

        

    def __str__(self):
        return str(self.id) + " port:" + str(self.port) + " level:" + str(self.level) + " parent:" + str(self.parent)
    

    def print_neighbours(self):
        for node in self.neighbours:
            print(node)

    def add_neighbour(self,neighbour_id,neighbour_port,neighbour_level):
        neighbour = self.Neighbour(neighbour_id,neighbour_port,neighbour_level)
        self.neighbours.append(neighbour)

    def pick_parent(self):
        if self.parent is None:
            
            self.parent = random.choice(self.neighbours)

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
            for n in self.neighbours:
                if n.level < self.total_nodes - 1:
                    self.privilege = 3
                    break

    def notify_central_daemon_of_privilege(self):
        if self.privilege >=0:
            print(f"[NODE {self.id}]: Notifying CD")
            try:
                self.sock.close()
                del(self.sock)
                print(f"[NODE {self.id}]: try socket deleted")

            except:
                pass

            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.bind((constants.HOST,self.port))
            self.sock.connect((constants.HOST, constants.CENTRAL_DAEMON_PORT))
            privilege_str = f'privilege {self.privilege}'
            self.sock.sendall(privilege_str.encode('ASCII'))
            self.sock.close()
            del(self.sock)
            print(f"[NODE {self.id}]: CD notified and socket destroyed")


    def refresh_privilege(self):
        if self.parent:
            self.check_privilege()
            print(f"[NODE {self.id}]: during refresh privilege {self.privilege}")
            self.notify_central_daemon_of_privilege()

        print(f"[NODE {self.id}]: After refresh privilege {self.privilege}")

    def accept_data(self):
        
        conn,addr = self.sock.accept()
        with conn:
            print(f"[Node {self.id}]:Connected by ", addr)
            
            data = conn.recv(1024)
            self.handle_rcv_data(addr,data)

        

    def listen(self):
        # print(f"[Node {self.id}]: Socket status: {self.sock}")
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((constants.HOST,self.port))
        self.sock.listen()
        print(f"[Node {self.id}]: listening")
        while self.sock:
            self.accept_data()


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
        self.listen()    