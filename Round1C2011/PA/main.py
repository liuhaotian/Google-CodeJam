#!/usr/bin/python
def main():
	fin = open("input.in", "r")
	fout = open("output.out", "w")

	T = int(fin.readline())

	for testcase in range(1, T + 1):
		R,C=[int(w) for w in fin.readline().split()]
		#[float(w) for w in fin.readline().split()]
		tab = []
		
		for r in range(R):
			tab += fin.readline().split()[:]

		try:
			for r in range(R):
				for c in range(C):
					if tab[r][c] == '#':
						line1 = list(tab[r])
						line2 = list(tab[r + 1])
						if ('#' in line1[c:c+2]) == False or ('#' in line2[c:c+2]) == False:
							raise Exception()

						line1[c]=line2[c+1]='/'
						line2[c]=line1[c+1]='\\'
						tab[r] = "".join(line1)
						tab[r + 1] = ''.join(line2)
				tab[r] += '\n'
			out = tab
			fout.write( 'Case #%d:\n' % testcase)
			for r in xrange(R):
				fout.write(out[r])
		except Exception:
			out = ['Impossible\n']
			for r in xrange(R):
				print tab[r]
			fout.write( 'Case #%d:\n' % testcase)
			fout.write(out[0])



if __name__ == '__main__':
	main()