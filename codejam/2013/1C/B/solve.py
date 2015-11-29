import sys
import re
from collections import defaultdict


inf = sys.stdin
outf = sys.stdout


def handle_case(case_num):
    case_str = 'Case #{0}: '.format(case_num)
    tx, ty = map(int, inf.readline().strip().split())
    paths = defaultdict(list)
    current_points = set([(0, 0)])
    for i in range(1, 600):
        next_current_points = []
        for x, y in next_current_points:
            for letter, dmx, dmy in [
                    ('N', 0, 1),
                    ('E', -1, 0),
                    ('S', 0, -1),
                    ('W', 1, 0)]:
                pass

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
