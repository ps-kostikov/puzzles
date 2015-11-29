import sys
import re


def add_dir(root, str):
    dirs = str[1:].split('/')
    current_dir = root
    mkdir_number = 0
    for d in dirs:
        if d in current_dir:
            current_dir = current_dir[d]
        else:
            current_dir[d] = {}
            current_dir = current_dir[d]
            mkdir_number += 1
        # print root
    return mkdir_number


def handle_case(case_num):
    N, M = map(int, sys.stdin.readline().split())
    root = {}
    for i in range(N):
        add_dir(root, sys.stdin.readline().strip())

    sum = 0
    for i in range(M):
        sum += add_dir(root, sys.stdin.readline().strip())
    print 'Case #%s: %s' % (case_num, sum)


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()