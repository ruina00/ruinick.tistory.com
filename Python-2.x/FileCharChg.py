# -*- coding: utf-8 -*-
import sys
 
def decode(alphabet,ciphertext,key):
	dic={}
	for i in range(0,len(key)):
		dic[key[i]]=alphabet[i]
 
	plaintext=""
	for l in ciphertext:
		if l in dic:
			l=dic[l]
		plaintext+=l
	return plaintext
 
if __name__ == "__main__":
	f = open('a.txt', "rb")
	ciphertext = f.read()
 
	print decode("abcdefghijklmnopqrstuvwxyz", ciphertext, "nopqrstuvwxyzabcdefghijklm")
