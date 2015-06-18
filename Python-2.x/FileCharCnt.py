# -*- coding: utf-8 -*-
import sys, collections
 
if __name__ == "__main__":
	f = open(sys.argv[1], "rb")
	text = f.read()
	count = collections.Counter(text)
	print count
