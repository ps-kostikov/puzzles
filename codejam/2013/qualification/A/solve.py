import sys
import re


inf = sys.stdin
outf = sys.stdout


def handle_case(case_num):
    # import ipdb; ipdb.set_trace()
    rows = []
    for i in range(4):
        rows.append(inf.readline().strip())
    inf.readline()

    def column(i):
        c = ''
        for r in rows:
            c += r[i]
        return c

    def backslash_diag():
        d = ''
        for i in range(4):
            d += rows[i][i]
        return d

    def slash_diag():
        d = ''
        for i in range(4):
            d += rows[i][3-i]
        return d

    variants = []
    for r in rows:
        variants.append(r)
    for i in range(4):
        variants.append(column(i))
    variants.append(backslash_diag())
    variants.append(slash_diag())

    complete = True
    for v in variants:
        if '.' in v:
            complete = False
        if v.replace('T', 'X') == 'XXXX':
            print >>outf, 'Case #{0}: X won'.format(case_num)
            return
        if v.replace('T', 'O') == 'OOOO':
            print >>outf, 'Case #{0}: O won'.format(case_num)
            return
    if complete:
        print >>outf, 'Case #{0}: Draw'.format(case_num)
    else:
        print >>outf, 'Case #{0}: Game has not completed'.format(case_num)


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
