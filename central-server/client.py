import os
import time
import json
import socket


CENTRAL_HOST = '192.168.0.53'
DISTRIBUTED_HOST = '192.168.0.4'
CENTRAL_PORT = 10019
DISTRIBUTED_PORT = 10119


def sender(socket_):
    while socket_.connect_ex((DISTRIBUTED_HOST, DISTRIBUTED_PORT)) != 0:
        print("Connecting to the distributed server...")
        time.sleep(1)
    while True:
        command = input()
        socket_.sendall(bytes(command, 'utf-8'))
        if command == 'quit':
            os.kill(os.getpid(), signal.SIGINT)

def receiver(socket_):
    socket_ = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_.bind((CENTRAL_HOST, CENTRAL_PORT))
    socket_.listen()
    conn, addr = socket_.accept()

    while True:
        data = conn.recv(1024)
        if data:
            data = json.loads(data)
            print(data)
        else:
            break
