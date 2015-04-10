#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1, total_T + 1):
		row_1 = int(f.readline())
		squ_1 = []
		for x in xrange(1, 4 + 1):
			squ_1.append(map(int, f.readline().rstrip('\n').split()))
		num_1 = set(squ_1[row_1-1])
		row_2 = int(f.readline())
		squ_2 = []
		for x in xrange(1, 4 + 1):
			squ_2.append(map(int, f.readline().rstrip('\n').split()))
		num_2 = set(squ_2[row_2-1])

		nums = num_1 & num_2
		if len(nums) == 1:
			print 'Case #{}: {}'.format(T, list(nums)[0])
		elif len(nums) > 1:
			print 'Case #{}: Bad magician!'.format(T)
		else:
			print 'Case #{}: Volunteer cheated!'.format(T)

		

if __name__ == '__main__':
	main()