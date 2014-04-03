#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		r,t = f.readline().rstrip('\n').split()
		r,t = int(r),int(t)

		# print r,t

		print 'Case #{}: {}'.format(T, solver(r, t))

def solver(r, t):
	return find_n(r, t, long(x2(2, 2*r-1, -t)))


def find_n(r, t, n):
	if total(r, n) <= t < total(r, n+1):
		return n
	elif total(r, n+1) <= t:
		return find_n(r, t, n+1)
	elif total(r, n) > t:
		return find_n(r, t, n-1)

def total(r, n):
	v = 2*n*n+2*n*r-n
	# print r,n,v
	return v

def x2(a,b,c):
	if a == 0:
		return -c/b
	elif a<0:
		return x2(-a, -b, -c)
	else:
		from math import sqrt
		return (-b + sqrt(b*b-4*a*c))/(2*a)


if __name__ == '__main__':
	main()