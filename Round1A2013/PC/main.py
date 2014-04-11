#!/usr/bin/env python

from collections import defaultdict
from copy import deepcopy

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		print 'Case #{}:'.format(T)
		R,N,M,K = map(long, f.readline().rstrip('\n').split())
		d = build_dict(N, M)
		d = perpare_d(d, M)
		# print d
		for k in xrange(R):
			p = map(long, f.readline().rstrip('\n').split())
			# pp = map(lambda x:d[x], filter(lambda x:x!=1, p))
			pp = map(lambda x:d[x], p)
			pp = sorted(pp, key=lambda x:len(x))

			r = merge(pp[0], pp[1], pp[2:], N)
			r = perpare_result(r, N)
			print r

def perpare_result(l, N):
	r = list(l[0])
	while len(r)<N:
		r.append(r[0])

	return ''.join(map(lambda x:x[0], r))



def perpare_d(d, M):
	d[1] = []
	for i in xrange(2, M+1):
		d[1].append([i])

	new_d = {}
	for k in d:
		new_d[k] = []
		for l in d[k]:
			s = set(l)
			new_l = set()
			for ss in s:
				new_l |= set(map(lambda x:''.join(x), zip(     [str(ss)]*l.count(ss),   map(str, xrange(l.count(ss)))   )    ))
			new_d[k].append(new_l)


	return new_d


def merge(a, b, l, N):
	new_l = []
	for aa in a:
		for bb in b:
			ab = aa|bb
			if len(ab) <= N and ab not in new_l:
				new_l.append(ab)

	if l == []:
		return new_l
	else:
		return merge(new_l, l[0], l[1:], N)


def build_dict(N, M):
	if N==1:
		d = {}
		for m in xrange(2, M+1):
			d.setdefault(m, []).append([m])

		return d
	
	old_d = build_dict(N-1, M)
	new_d = deepcopy(old_d)
	for k in old_d:
		v = old_d[k]
		for m in xrange(2, M+1):
			for vv in v:
				vvv = deepcopy(vv)
				vvv.append(m)
				vvv = sorted(vvv)
				if vvv not in new_d.setdefault(k*m, []):
					new_d[k*m].append(vvv)

	return new_d


if __name__ == '__main__':
	main()