#!/usr/bin/env python


def main():
    fin = open('input.txt', 'r')

    total_T = int(fin.readline())

    for T in xrange(1, total_T + 1):
        K, C, S = map(int, fin.readline().rstrip('\n').split())

        if S * C < K:
            print 'Case #{}: IMPOSSIBLE'.format(T)
            continue


            

        print 'Case #{}: {}'.format(T, ' '.join(map(lambda i: str(i+1), helper(K, C))))

def helper(K, C):
    for k in xrange(0, K, C):
        res = sum((K**(C-c-1))*(k+c) for c in xrange(0, C) if k+c<K)
        yield res
        


if __name__ == '__main__':
    main()