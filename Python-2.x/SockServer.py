# -*- coding: utf-8 -*-
from socket import *
 
if __name__ == "__main__":
	s = socket(AF_INET, SOCK_STREAM)
	s.bind(("127.0.0.1", 9000))
	s.listen(1)
	conn, addr = s.accept()
	recv_data = conn.recv(1024)
	print 'Received Data : ' + recv_data
	s.close()
