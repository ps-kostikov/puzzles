import sys
import re

def print_result(m):
    for line in range(len(m)):
        print ''.join(c for c in line)


def handle_case(case_num):
    R, C = map(int, sys.stdin.readline().split())
    matrix = []
    for i in range(R):
        matrix.append(list(sys.stdin.readline().strip()))
        assert len(matrix[i]) == C

    possible = True
    for i in range(R):
        if not possible:
            break
        for j in range(C):
            if matrix[i][j] != '#':
                continue
            if i + 1 >= R or j + 1 >= C:
                possible = False
                break
            if matrix[i+1][j] != '#' or \
                    matrix[i][j+1] != '#' or \
                    matrix[i+1][j+1] != '#':
                possible = False
                break
            matrix[i][j] = '/'
            matrix[i+1][j] = '\\'
            matrix[i][j+1] = '\\'
            matrix[i+1][j+1] = '/'



    print 'Case #%s:' % case_num
    if possible:
        for line in matrix:
            print ''.join(c for c in line)
    else:
        print 'Impossible'


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()