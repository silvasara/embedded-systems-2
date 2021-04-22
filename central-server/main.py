import sys
import signal
import socket
import threading
import os

from client import sender, receiver
from log_csv import create_csv, save_csv

send_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
recv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

csv_file, writer = create_csv()


def signal_handler(sig, _):
    send_socket.close()
    save_csv(csv_file)
    recv_socket.close()
    os.kill(os.getpid(), signal.SIGINT)
    sys.exit(0)


if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)

    receiver_thread = threading.Thread(target=receiver, args=(recv_socket, writer))
    sender_thread = threading.Thread(target=sender, args=(send_socket,))

    sender_thread.start()
    receiver_thread.start()

