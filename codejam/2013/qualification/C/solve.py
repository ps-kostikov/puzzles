import sys
import re
import math


inf = sys.stdin
outf = sys.stdout


def is_fair(n):
    s = str(n)
    return s == s[::-1]


fair_and_squares = []


def init():
    global fair_and_squares
    a, b = 1, 2 * (10 ** 7)
    for c in range(a, b):
        c2 = c * c
        if is_fair(c) and is_fair(c2):
            fair_and_squares.append(c2)


def handle_case(case_num):
    A, B = map(int, inf.readline().strip().split())

    res = 0
    for c in fair_and_squares:
        if c >= A and c <= B:
            res += 1
    case_str = 'Case #{0}: '.format(case_num)
    print >>outf, '{0}{1}'.format(case_str, res)


def main():
    if len(sys.argv) > 1:
        global inf
        inf = open(sys.argv[1])
    if len(sys.argv) > 2:
        global outf
        outf = open(sys.argv[2], 'w')

    T = int(inf.readline().strip())
    init()
    for case_num in xrange(1, T+1):
        handle_case(case_num)

    if inf != sys.stdin:
        inf.close()
    if outf != sys.stdout:
        outf.close()


if __name__ == '__main__':
    main()
