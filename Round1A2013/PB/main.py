#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		E,R,N = map(long, f.readline().rstrip('\n').split())
		v = map(long, f.readline().rstrip('\n').split())

		# print E,R,N
		# print v

		print 'Case #{}: {}'.format(T, Gain(E, R, E, R, v))

def Gain(Ein, Eout, Emax, R, v):
	if len(v) < 1:
		return 0
	Imax = v.index(max(v))
	EMbefore = R*Imax + Ein
	EMafter = Eout - R*(len(v) - Imax)
	if EMbefore >= Emax and EMafter <= 0:
		return Gain(Ein, Emax, Emax, R, v[:Imax]) + Emax * v[Imax] + Gain(R, Eout, Emax, R, v[Imax+1:])
	elif EMbefore < Emax and EMafter <= 0:
		return EMbefore*v[Imax] + Gain(R, Eout, Emax, R, v[Imax+1:])
	elif EMbefore >= Emax and EMafter > 0:
		return Gain(Ein, Emax, Emax, R, v[:Imax]) + (Emax - EMafter)*v[Imax]
	else:
		return (EMbefore - EMafter) * v[Imax]


if __name__ == '__main__':
	main()