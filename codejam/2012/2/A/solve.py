import sys
import re


def handle_case(case_num):
    N = int(sys.stdin.readline())
    dls = []
    for i in range(N):
        d, l = map(int, sys.stdin.readline().split())
        dls.append((d, l))
    D = int(sys.stdin.readline())

    current_index = 0
    current_pos = 0
    while current_pos + 2 * (dls[current_index][0] - current_pos) < D:
        next_index = None
        for ii in range(current_index + 1, len(dls)):
            d = dls[current_index][0]
            l = d - current_pos
            nd, nl = dls[ii]
            if nd > current_pos + 2 * l:
                break

            if nd + nl >= D and ii == len(dls) - 1:
                print 'Case #%s: YES' % (case_num)
                return

            if nl >= nd - d + l:
                next_index = ii


        if next_index is None:
            print 'Case #%s: NO' % (case_num)
            return

        current_pos = dls[current_index][0]
        current_index = next_index
        # print 'current index = %s, current_post = %s' % (next_index, current_pos)

    print 'Case #%s: YES' % (case_num)


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()