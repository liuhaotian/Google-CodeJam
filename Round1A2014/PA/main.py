#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N,L = map(int, f.readline().rstrip('\n').split())
		outlets = map(lambda x:int(x, 2), f.readline().rstrip('\n').split())
		devices = map(lambda x:int(x, 2), f.readline().rstrip('\n').split())
		# print outlets, devices
		L = [set(map(lambda x: x^d, outlets)) for d in devices]
		L = reduce(lambda x, y: x & y, L)
		# print L
		# print len(L)

		if len(L) == 0:
			print 'Case #{}: NOT POSSIBLE'.format(T)
		else:
			c = min(sum(1 if x=='1' else 0 for x in bin(l))	for l in list(L))
			print 'Case #{}: {}'.format(T, c)



if __name__ == '__main__':
	main()