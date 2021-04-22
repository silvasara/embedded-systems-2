import os
import time
import json
import socket
import curses
import signal

from log_csv import write_rows
from menu import Menu, Output


CENTRAL_HOST = '192.168.0.53'
DISTRIBUTED_HOST = '192.168.0.4'
CENTRAL_PORT = 10019
DISTRIBUTED_PORT = 10119

stdscr = curses.initscr()
curses.noecho()
curses.cbreak()
stdscr.keypad(True)


def sender(socket_):
    menu = Menu(stdscr)
    while socket_.connect_ex((DISTRIBUTED_HOST, DISTRIBUTED_PORT)) != 0:
        menu.show_info("Connecting to the distributed server...")
        time.sleep(1)

    while True:
        command = menu.get_user_input()
        socket_.sendall(bytes(command, 'utf-8'))


def receiver(socket_, writer):
    socket_ = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_.bind((CENTRAL_HOST, CENTRAL_PORT))
    socket_.listen()
    conn, addr = socket_.accept()

    menu = Output(stdscr)
    while True:
        data = conn.recv(1024)
        if data:
            data = json.loads(data)
            menu.show_data(data)
            write_rows(writer, data)
        else:
            break
