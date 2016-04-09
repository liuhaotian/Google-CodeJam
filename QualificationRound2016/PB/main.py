#!/usr/bin/env python

def main():
	fin = open('input.txt', 'r')

	total_T = int(fin.readline())

	for T in xrange(1, total_T + 1):
		S = list(fin.readline().rstrip('\n'))

		print 'Case #{}: {}'.format(T, helper(S, '+'))


def helper(S, want='+'):
	if len(S) == 1 and S[0] == want:
		return 0
	elif len(S) == 1 and S[0] != want:
		return 1
	elif S[-1] == want:
		return helper(S[:-1], want)
	else:
		# unwanted in the end
		return 1 + helper(S, '-' if want == '+' else '+')








if __name__ == '__main__':
	main()