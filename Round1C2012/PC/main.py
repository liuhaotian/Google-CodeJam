#!/usr/bin/python

class outatom():
    def __init__(self):
        self.count = 0
        self.boxleft = [0,0]
        self.toyleft = [0,0]

def main():
    fin = open('input.txt', 'r')
    T = int(fin.readline())
    for t in xrange(T):
        N, M = fin.readline().split()
        N = int(N)
        M = int(M)
        box = fin.readline().split()
        box = [[0,0]]+[ [int(x),int(y)] for x,y in zip(box[0::2],box[1::2])]+[[0,0]]
        toy = fin.readline().split()
        toy = [[0,0]]+[ [int(x),int(y)] for x,y in zip(toy[0::2],toy[1::2])]+[[0,0]]
        #print `N`+' '+`M`
        #print `box`
        #print `toy`
        # out[N,M]
        out = [[outatom() for y in xrange(M+2)] for x in xrange(N+2)]

        for i in xrange(1,N+2):
            for j in xrange(1,M+2):
                if box[i][1] == toy[j][1]:
                    if box[i][1] == out[i-1][j].toyleft[1]:
                        totalbox = box[i][0]
                        totaltoy = out[i-1][j].toyleft[0]

                        out[i][j].count = min(totalbox,totaltoy) + out[i-1][j].count
                        if totalbox > totaltoy:
                            out[i][j].boxleft = [totalbox-totaltoy,box[i][1]]
                        elif totalbox < totaltoy:
                            out[i][j].toyleft = [totaltoy-totalbox,box[i][1]]
                    elif toy[j][1] == out[i][j-1].boxleft[1]:
                        totalbox = out[i][j-1].boxleft[0]
                        totaltoy = toy[j][0]

                        out[i][j].count = min(totalbox,totaltoy) + out[i][j-1].count
                        if totalbox > totaltoy:
                            out[i][j].boxleft = [totalbox-totaltoy,toy[j][1]]
                        elif totalbox < totaltoy:
                            out[i][j].toyleft = [totaltoy-totalbox,toy[j][1]]
                    else:
                        totalbox = box[i][0]
                        totaltoy = toy[j][0]

                        out[i][j].count = min(totalbox,totaltoy) + out[i-1][j-1].count
                        if totalbox > totaltoy:
                            out[i][j].boxleft = [totalbox-totaltoy,box[i][1]]
                        elif totalbox < totaltoy:
                            out[i][j].toyleft = [totaltoy-totalbox,box[i][1]]


                elif box[i][1] == out[i-1][j].toyleft[1]:
                    totalbox = box[i][0]
                    totaltoy = out[i-1][j].toyleft[0]
                    if min(totalbox,totaltoy) + out[i-1][j].count >= out[i][j-1].count:
                        out[i][j].count = min(totalbox,totaltoy) + out[i][j-1].count
                        if totalbox > totaltoy:
                            out[i][j].boxleft = [totalbox-totaltoy,box[i][1]]
                        elif totalbox < totaltoy:
                            out[i][j].toyleft = [totaltoy-totalbox,box[i][1]]
                    else:
                        out[i][j].count = out[i][j-1].count
                        out[i][j].boxleft = out[i][j-1].boxleft
                elif toy[j][1] == out[i][j-1].boxleft[1]:
                    totalbox = out[i][j-1].boxleft[0]
                    totaltoy = toy[j][0]
                    if min(totalbox,totaltoy) + out[i][j-1].count >= out[i-1][j].count:
                        out[i][j].count = min(totalbox,totaltoy) + out[i][j-1].count
                        if totalbox > totaltoy:
                            out[i][j].boxleft = [totalbox-totaltoy,toy[j][1]]
                        elif totalbox < totaltoy:
                            out[i][j].toyleft = [totaltoy-totalbox,toy[j][1]]
                    else:
                        out[i][j].count = out[i-1][j].count
                        out[i][j].toyleft = out[i-1][j].toyleft
                else:
                    if out[i-1][j].count >= out[i][j-1].count:
                        out[i][j].count = out[i-1][j].count
                        out[i][j].toyleft = out[i-1][j].toyleft
                    else:
                        out[i][j].count = out[i][j-1].count
                        out[i][j].boxleft = out[i][j-1].boxleft

        print `out[N][M].count`

    fin.close()

if __name__ == '__main__':
    main()