import sys
import re


inf = sys.stdin
outf = sys.stdout


vowels = ['a', 'e', 'i', 'o', 'u']


def appropriate(s, n):
    current_length = 0
    for c in s:
        if c in vowels:
            current_length = 0
        else:
            current_length += 1
            if current_length >= n:
                return True
    return False


def handle_case(case_num):
    case_str = 'Case #{0}: '.format(case_num)
    name, n = inf.readline().strip().split()
    n = int(n)
    L = len(name)
    res = 0
    for i in range(L):
        for j in range(i + 1, L + 1):
            # print name[i:j]
            # print i, j
            if appropriate(name[i:j], n):
                res += 1 
    print >>outf, case_str, res


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
