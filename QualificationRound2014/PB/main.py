#!/usr/bin/env python

def main():
	fin = open('input.txt', 'r')

	total_T = int(fin.readline())

	for T in xrange(1, total_T + 1):
		C, F, X = map(float, fin.readline().rstrip('\n').split())
		
		t = 0
		f = 2
		t0 = X/2
		while f < F*X/C:
			t += C/f
			f += F
			t0 = min(t0, t+X/f)

		print 'Case #{}: {:.7f}'.format(T, t0)



if __name__ == '__main__':
	main()