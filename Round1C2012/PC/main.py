def main():
	fin = open('input.txt', 'r')
	T = int(fin.readline())
	N, M = fin.readline().split()
	N = int(N)
	M = int(M)
	box = fin.readline().split()
	box = [ [int(x),int(y)] for x,y in zip(box[0::2],box[1::2])]
	toy = fin.readline().split()
	toy = [ [int(x),int(y)] for x,y in zip(toy[0::2],toy[1::2])]


if __name__ == '__main__':
	main()