import sys
import re


inf = sys.stdin
outf = sys.stdout


def handle_case(case_num):
    rn, cn = map(int, inf.readline().strip().split())
    matrix = []
    for i in range(rn):
        matrix.append(map(int, inf.readline().strip().split()))

    maxs_r = [max(r) for r in matrix]
    maxs_c = [max([r[j] for r in matrix]) for j in range(cn)]

    res = 'YES'
    for i in range(rn):
        for j in range(cn):
            el = matrix[i][j]
            res_el = min(maxs_r[i], maxs_c[j])
            if el != res_el:
                res = 'NO'
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
    for case_num in xrange(1, T+1):
        handle_case(case_num)

    if inf != sys.stdin:
        inf.close()
    if outf != sys.stdout:
        outf.close()


if __name__ == '__main__':
    main()
