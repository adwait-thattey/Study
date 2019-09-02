import random
import socket
import constants
import threading

PRIVILEGED_NODES = list()
OPENED_SOCKET = None

class CentralDaemon(threading.Thread):
    def __init__(self):
        """
        """

        super().__init__()
        self.port = constants.CENTRAL_DAEMON_PORT
    
        # self.privileged_nodes = list()
        self.received_privilege_pings = 0

    class ListenerThread(threading.Thread):
        def __init__(self):
            """
            """
            super().__init__()
            self.event = threading.Event()
            # self.privileged_nodes = list()
            self.stop_flag = False
            self.connection = None
        def run(self):
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.bind((constants.HOST, constants.CENTRAL_DAEMON_PORT))
            self.sock.listen()
            print("[CD]: Central thread listning")
            while True:
                if self.stop_flag:
                    print("[CD]: Ending listen thread")
                    break
                
                self.accept_data()

            self.sock.close()
            del(self.sock)

        def accept_data(self):
            conn,addr = self.sock.accept()
            self.connection = conn
            
            with conn:
                print('[CD]: Connected by', addr)
                
                data = conn.recv(1024)
                self.handle_rcv_data(addr,data)
    
        def handle_rcv_data(self,addr,data):            
            global PRIVILEGED_NODES
            decoded_data = data.decode()
            print(f"[CD]: received data: [{addr}]: ", decoded_data)
            split_data = decoded_data.split(' ')
            if split_data[0] == "privilege":
                if int(split_data[1]) >= 0:
                    PRIVILEGED_NODES.append((addr,split_data[1]))            

        def stop(self):
            print("[CD]: Stop flag set to true")
            self.stop_flag = True
            newsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            newsock.connect((constants.HOST, constants.CENTRAL_DAEMON_PORT))
            newsock.sendall(b'close')
            newsock.close()


    def run(self):
        while True:
            global PRIVILEGED_NODES
            PRIVILEGED_NODES = list()

            listener_thread = self.ListenerThread()
            listener_thread.start()
            listener_thread.join(3)
            # OPENED_SOCKET.close()
            print("[CD]: Terminating thread")
            if listener_thread.is_alive():
                print("[CD]: Thread still alive!")
                listener_thread.stop()
                # listener_thread.event.set()
            listener_thread.join()
            print("[CD]: Daemon thread END")
            if len(PRIVILEGED_NODES) <=0:
                print("[CD]: Spanning Tree reached")
                break
            else:
                print(PRIVILEGED_NODES)
                self.choose_privilege_node()


    def choose_privilege_node(self):
        chosen_node = random.choice(PRIVILEGED_NODES)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((constants.HOST, constants.CENTRAL_DAEMON_PORT))
        self.sock.connect((constants.HOST, chosen_node[0][1]))
        privilege_str = f'privilege'
        self.sock.sendall(privilege_str.encode('ASCII'))
        self.sock.close()
        del(self.sock)

        