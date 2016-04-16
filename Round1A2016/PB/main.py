#!/usr/bin/env python
from collections import deque, Counter


def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())


	for T in xrange(1,total_T+1):
		N = int(f.readline().rstrip('\n'))
		# print N
		lists = [map(int, f.readline().rstrip('\n').split()) for i in xrange(2*N-1)]
		
		lists_prev = [l for l in lists if l[0] == min(ll[0] for ll in lists)]
		if len(lists_prev) == 1:
			miss = 0
			list_other = lists_prev[0]
		else:
			for i in xrange(1, N):
				lists_current = [ll for ll in lists if ll[i] == min(l[i] for l in lists if l[i] > max(lists_prev[0][i], lists_prev[1][i]))]
				if len(lists_current) == 1:
					miss = i
					list_other = lists_current[0]
					break
				else:
					lists_prev = lists_current


		d = Counter()
		for l in lists:
			d[l[miss]] += 1
		d[list_other[miss]] += 1
		# print d
		for i in list_other:
			d[i] -= 1




		print 'Case #{}: {}'.format(T, ' '.join(map(str, sorted([k for k in d.keys() if d[k]>0]))))



if __name__ == '__main__':
	main()