#!/usr/bin/python

class outatom():
    def __init__(self):
        self.count = 0
        self.boxleft = [0,0]
        self.toyleft = [0,0]
class dropbox():
    def __init__(self):
        self.count = 0
        self.boxleft = [0,0]
        self.toyleft = [0,0]
class droptoy():
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
        prevbox = [0]*101
        prevtoy = [0]*101

        for i in xrange(N+2):
            out[i][0].boxleft = box[i]
        for i in xrange(M+2):
            out[0][i].toyleft = toy[i]

        for i in xrange(1,N+1):
            for j in xrange(1,M+1):
                if box[i][1] == toy[j][1]:
                    totalbox = box[i][0]
                    totaltoy = toy[j][0]
                    count1 = out[i-1][j-1].count + min(totalbox,totaltoy)
                    boxleft1 = [max(totalbox-totaltoy,0),box[i][1]]
                    toyleft1 = [max(totaltoy-totalbox,0),toy[j][1]]

                    prevtoyindex = prevtoy[toy[j][1]]
                    if prevtoyindex > 0:
                        totalbox = out[i][prevtoyindex].boxleft[0]
                        totaltoy = toy[j][0] + out[i][prevtoyindex].toyleft[0]
                        count2 = out[i][prevtoyindex].count + min(totalbox,totaltoy)
                        boxleft2 = [max(totalbox-totaltoy,0),box[i][1]]
                        toyleft2 = [max(totaltoy-totalbox,0),toy[j][1]]
                    else:
                        count2 = count1
                        boxleft2 = boxleft1
                        toyleft2 = toyleft1

                    prevboxindex = prevbox[box[i][1]]
                    if prevboxindex > 0:
                        totalbox = box[i][0] + out[prevboxindex][j].boxleft[0]
                        totaltoy = out[prevboxindex][j].toyleft[0]
                        count3 = out[prevboxindex][j].count + min(totalbox,totaltoy)
                        boxleft3 = [max(totalbox-totaltoy,0),box[i][1]]
                        toyleft3 = [max(totaltoy-totalbox,0),toy[j][1]]
                    else:
                        count3 = count1
                        boxleft3 = boxleft1
                        toyleft3 = toyleft1

                    for count,boxleft,toyleft in zip([count1,count2,count3],[boxleft1,boxleft2,boxleft3],[toyleft1,toyleft2,toyleft3]):
                        if count == max([count1,count2,count3]):
                            out[i][j].count = max(count,out[i][j].count)
                            out[i][j].boxleft = max(boxleft,out[i][j].boxleft)
                            out[i][j].toyleft = max(toyleft,out[i][j].toyleft)
                            print "i:%d,j:%d,c:%d,b:%d,t:%d" % (i,j,out[i][j].count,out[i][j].boxleft[0],out[i][j].toyleft[0])
                else:
                    out[i][j].count = max(out[i-1][j-1].count,out[i-1][j].count,out[i][j-1].count)
                    out[i][j].boxleft = box[i]
                    out[i][j].toyleft = toy[j]
                    print "i:%d,j:%d,c:%d,b:%d,t:%d" % (i,j,out[i][j].count,out[i][j].boxleft[0],out[i][j].toyleft[0])


                prevtoy[toy[j][1]] = j
            prevbox[box[i][1]] = i


        print 'Case #'+str(t+1)+": "+`out[N][M].count`

    fin.close()

if __name__ == '__main__':
    main()