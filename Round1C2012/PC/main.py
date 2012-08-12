#!/usr/bin/python
def main():
    fin = open('input.txt', 'r')
    T = int(fin.readline())
    for t in xrange(T):
        N, M = fin.readline().split()
        N = int(N)
        M = int(M)
        box = fin.readline().split()
        box = [ [int(x),int(y)] for x,y in zip(box[0::2],box[1::2])]
        toy = fin.readline().split()
        toy = [ [int(x),int(y)] for x,y in zip(toy[0::2],toy[1::2])]
        #print `N`+' '+`M`
        #print `box`
        #print `toy`
        # out[N,M]
        out = [[0]*M for x in xrange(N)]

        for i in xrange(N):
            for j in xrange(M):
                if box[i][1] == toy[j][1]:
                    if i-1>=0 and j-1>=0:
                        out[i][j] = out[i-1][j-1] + min([box[i][0],toy[j][0]])
                    else:
                        out[i][j] = min([box[i][0],toy[j][0]])
                else:
                    if i-1>=0 and j-1>=0:
                        out[i][j] = max(out[i-1][j],out[i][j-1])
                    elif i-1>=0 and j-1<0:
                        out[i][j] = out[i-1][j]
                    elif i-1<0 and j-1>=0:
                        out[i][j] = out[i][j-1]
                    elif i==0 and j==0:
                        out[i][j] = 0
        print `out[N-1][M-1]`

    fin.close()

if __name__ == '__main__':
    main()