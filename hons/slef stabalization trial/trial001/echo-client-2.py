#!/usr/bin/env python3

import socket
import time

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, 63254))
    s.connect((HOST, PORT))
    while True:

        s.sendall(b'privilege')
        data = s.recv(1024)
        print('Received', repr(data))
        time.sleep(2)
