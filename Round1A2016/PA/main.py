#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	alphabeta = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
	d = {alphabeta[i]:i for i in xrange(26)}

	for T in xrange(1,total_T+1):
		S = f.readline().rstrip('\n')

		new_S = [S[0]]
		for s in S[1:]:
			# print s,d[s],new_S[0],d[new_S[0]]
			if d[s] >= d[new_S[0]]:
				new_S.insert(0, s)
			else:
				new_S.append(s)

		print 'Case #{}: {}'.format(T, ''.join(new_S))


if __name__ == '__main__':
	main()