import sys
import re


inf = sys.stdin
outf = sys.stdout


def level_max_n(level):
    # level >= 1
    if level < 1:
        return 0
    return level * (2 * level - 1)


def prob(x, n):
    # C iz n po x
    pass


def handle_case(case_num):
    N, X, Y = map(int, inf.readline().strip().split())
    level = (X + Y) / 2 + 1

    if level_max_n(level - 1) >= N:
        res = 0.
    elif N >= level_max_n(level):
        res = 1.
    else:
        height = Y + 1
        level_height = level * 2 - 1
        n = N - level_max_n(level - 1)
        print height, level_height, n
        if height > n:
            res = 0.
        elif height == level_height and n < 2 * level_height - 1:
            res = 0.
        # if 
        # level_height = 
        else:
            # for x in range(height, n + 1):
            res = 0.4

    case_str = 'Case #{0}: {1}'.format(case_num, res)
    print >>outf, case_str


def main():
    if len(sys.argv) > 1:
        global inf
        inf = open(sys.argv[1])
    if len(sys.argv) > 2:
        global outf
        outf = open(sys.argv[2], 'w')

    T = int(inf.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)

    if inf != sys.stdin:
        inf.close()
    if outf != sys.stdout:
        outf.close()


if __name__ == '__main__':
    main()
