#!/usr/bin/env python

bases = [2, 3, 4, 5, 6, 7, 8, 9, 10]


def main():
    T = 1
    print 'Case #1:'
    N = 32
    J = 500
    # N = 6
    # J = 10

    NN = (1<<(N-1)) - 1
    count = 0
    while count < J:
        NN += 2
        # print bin(NN)[2:]
        divisors = {}
        for b in bases:
            # print NN, b, covert_10_to_base(NN, b)
            divisor = is_prime_or_divisor(covert_2_to_base(NN, b))
            if divisor is True:
                break
            else:
                divisors[b] = divisor
        if len(divisors) != len(bases):
            continue
        else:
            print bin(NN)[2:], ' '.join(map(str, divisors.itervalues()))
            count += 1

def covert_2_to_base(n, b):
    if b == 2:
        return n
    ret = 0
    bb = 1
    for nn in reversed(bin(n)[2:]):
        ret += int(nn) * bb
        bb *= b
    return ret


def xxrange(a, b):
    while a != b:
        yield a
        a += 1

def is_prime_or_divisor(a):
    for i in xxrange(2, 1091):
        if a % i == 0:
            return i
    return True

if __name__ == '__main__':
    main()