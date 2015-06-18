from itertools import product
 
chars = '0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm'	# Chars Dictionary
 
for length in range(1, 5):	# length 1 to 4
	to_attempt = product(chars, repeat=length)
	for attempt in to_attempt:
		brute = ''.join(attempt)
		print brute
