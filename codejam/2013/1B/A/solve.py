import sys
import re


inf = sys.stdin
outf = sys.stdout


def handle_case(case_num):
    A, N = map(int, inf.readline().strip().split())
    motes = map(int, inf.readline().strip().split())
    motes = sorted(modes)
    for m in motes:
        pass
    # print A, N
    # print motes
    case_str = 'Case #{0}: '.format(case_num)
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
