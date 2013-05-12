#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		A,N = f.readline().rstrip('\n').split()
		A,N = int(A),int(N)

		motes = f.readline().rstrip('\n').split()
		motes = map(int, motes)
		motes = sorted(motes)
		# print A,N
		# print motes

		print 'Case #{}: {}'.format(T, solver(A, motes))

def solver(A, motes):
	if motes == []:
		return 0
	elif A==1:
		return len(motes)
	# print A
	# print motes
	the_min = min(motes)

	if A > the_min:
		motes.remove(the_min)
		return solver(A+the_min, motes)
	elif 1<A<the_min<A+A-1:
		return 1+solver(A+A-1, motes)
	else:
		return min(len(motes), 1+solver(A+A-1, motes))


if __name__ == '__main__':
	main()