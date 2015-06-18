# -*- coding: utf-8 -*-
 
if __name__ == "__main__":
	data = "test"
 
	encode_string = data.encode('base64')		# Base64 Encoding
	print "encode string :", encode_string
 
	decode_string = encode_string.decode('base64')	# Base64 Decoding
	print "decode string :", decode_string
