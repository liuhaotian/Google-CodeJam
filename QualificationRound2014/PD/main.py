#!/usr/bin/env python

from collections import deque

def main():
	fin = open('input.txt', 'r')

	total_T = int(fin.readline())

	for T in xrange(1, total_T + 1):
		N = int(fin.readline().rstrip('\n'))
		# C, F, X = map(float, fin.readline().rstrip('\n').split())
		Naomi = map(float, fin.readline().rstrip('\n').split())
		Ken = map(float, fin.readline().rstrip('\n').split())
		Naomi = sorted(Naomi)
		Ken = sorted(Ken)

		# print Naomi
		# print Ken

		Naomi1 = [x for x in Naomi]
		Ken1 = [x for x in Ken]
		S1 = 0
		for n in Naomi1:
			k = filter(lambda x: x>n, Ken1)
			if k:
				Ken1.remove(k[0])
			else:
				S1 += 1

		# print S1

		Naomi2 = [x for x in Naomi]
		Ken2 = [x for x in Ken]
		S2 = 0
		n = filter(lambda x: x<min(Ken2), Naomi2)
		if n:
			S2 = len(Naomi2) - len(n)
		else:
			S2 = len(Naomi2)

		# print S2



		print 'Case #{}: {} {}'.format(T, S2, S1)



if __name__ == '__main__':
	main()