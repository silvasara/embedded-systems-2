import sys
import signal
import socket
import threading

from client import sender
from client import receiver

#send_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
recv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def signal_handler(sig, frame):
#    send_socket.close()
    recv_socket.close()
    sys.exit(0)


if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)

    receiver_thread = threading.Thread(target=receiver, args=(recv_socket,))
    #sender_thread = threading.Thread(target=sender, args=(send_socket,))

    receiver_thread.start()
    #sender_thread.start()

