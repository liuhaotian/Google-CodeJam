#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N,L = map(int, f.readline().rstrip('\n').split())
		outlets = f.readline().rstrip('\n').split()
		devices = f.readline().rstrip('\n').split()

		outlets = map(lambda x:long(x, 2), outlets)
		devices = map(lambda x:long(x, 2), devices)

		# print N,L
		# print outlets
		# print devices
		# print find(outlets, devices)

		print 'Case #{}: {}'.format(T, find(outlets, devices))

def find(outlets, devices):
	sets = [set(o^d for o in outlets) for d in devices]
	r = sets.pop()
	while sets != []:
		r &= sets.pop()

	if r ==set():
		return 'NOT POSSIBLE'
	return min(bin(x).count('1') for x in r)


if __name__ == '__main__':
	main()