#!/usr/bin/env python

from collections import Counter

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1, total_T + 1):
		N = int(f.readline().rstrip('\n'))

		if N == 0:
			print 'Case #{}: INSOMNIA'.format(T)
			continue

		cnt = [False for x in xrange(10)]
		
		n = N
		while True:
			for k in Counter(str(n)):
				cnt[int(k)] = True
				# print cnt
			if all(cnt):
				break
			else:
				n += N
				# print n

		
		print 'Case #{}: {}'.format(T, n)

		

if __name__ == '__main__':
	main()