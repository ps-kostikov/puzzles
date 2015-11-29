import sys
import re


def load_field():
    M, N = map(int, sys.stdin.readline.strip().split())
    field = [[0] * N for i in range(M)]
    pass

def handle_case(case_num):
    pass


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()