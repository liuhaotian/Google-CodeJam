#!/usr/bin/env python


def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1, total_T + 1):
		R,C,M = map(int, f.readline().rstrip('\n').split())
		# print R,C,M
		mine = Mine(R,C,M)
		# mine.prt()
		# mine.click(0,0)
		# mine.prt()
		# mine.revert(0,0)
		# mine.prt()
		res = resolve(mine)
		print 'Case #{}:'.format(T)
		if res is not None:
			mine.prt(final=True)
		else:
			print 'Impossible'
			# raw_input()

		# print 'Case #{}: {}'.format(T, sovler(0, S, d, cache))


def resolve(mine):
	li = [(0,0), (0,1), (1,0)]
	li = filter(lambda x:x[0]<mine.R and x[1]<mine.C, li)
	if mine.R*mine.C==mine.M+1:
		mine.mine[0][0] = '.'
		return mine

	while len(li)>0:
		# mine.prt()
		# print li
		# raw_input()
		
		r,c = li[-1]
		if mine.mine[r][c]=='.' or mine.mine[r][c]=='*':
			clicks = mine.click(r,c)
			m = mine.eval()
			if m == mine.M:
				return mine
			elif m > mine.M:
				li+=clicks
		else:
			r,c = li.pop()
			mine.revert(r,c)

	return None


class Mine(object):
	def __init__(self, R, C, M):
		self.R = R
		self.C = C
		self.M = M
		self.mine = [ [ '*' for c in xrange(C)] for r in xrange(R)]

	def prt(self, final=False):
		if final:
			for r in xrange(self.R):
				for c in xrange(self.C):
					if self.mine[r][c] != '*':
						self.mine[r][c]='.'
			self.mine[0][0]='c'
			for r in xrange(self.R):
				print ''.join(self.mine[r])
		else:
			for r in xrange(self.R):
				print ''.join('*' if ch =='*' else '.' for ch in self.mine[r])

	def eval(self):
		ret = 0
		for r in xrange(self.R):
			for c in xrange(self.C):
				if self.mine[r][c] == '*':
					ret+=1

		return ret

	def click(self, rr, cc):
		clicks = []
		# print 'click',rr,cc
		for r in xrange(max(rr-1, 0), min(rr+1, self.R-1) + 1):
			for c in xrange(max(cc-1,0), min(cc+1, self.C-1) + 1):
				if self.mine[r][c] == '*':
					self.mine[r][c] = '.'
					clicks.append((r,c))

		self.mine[rr][cc] = clicks
		return filter(lambda x:x[0]!=rr or x[1]!=cc, clicks)

	def revert(self, rr, cc):
		# print 'revert',rr,cc
		for b in list(self.mine[rr][cc]):
			r,c =b[0],b[1]
			self.mine[r][c] = '*'

		

if __name__ == '__main__':
	main()