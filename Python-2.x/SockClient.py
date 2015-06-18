# -*- coding: utf-8 -*-
from socket import *
 
if __name__ == "__main__":
    s = socket(AF_INET, SOCK_STREAM)
    s.connect(('127.0.0.1', 9000))
    s.send('Sock Client Send\n')
    s.close()
