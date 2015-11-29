import sys
import re


def read_matrix(N):
    matrix = []
    for i in range(N):
        matrix.append(sys.stdin.readline().strip())
    return matrix


def get_max_in_line(line, el):
    m = 0
    current = 0
    for l in line:
        if l == el:
            current += 1
        else:
            current = 0
        m = max(m, current)
    return m

def iter_horizontal(matrix):
    for line in matrix:
        yield line

def iter_vertical(matrix):
    for i in range(len(matrix)):
        yield ''.join([l[i] for l in matrix])

def get_line(matrix, point, direction):
    N = len(matrix)
    i, j = point
    di, dj = direction
    res = ''
    while i in range(N) and j in range(N):
        res += matrix[i][j]
        i += di
        j += dj
    return res

def iter_slash(matrix):
    N = len(matrix)
    for i in range(0, N - 1):
        yield get_line(matrix, (i, 0), (-1, 1))

    yield get_line(matrix, (N - 1, 0), (-1, 1))

    for j in range(1, N):
        yield get_line(matrix, (N - 1, j), (-1, 1))

def iter_backslash(matrix):
    N = len(matrix)
    for i in range(1, N):
        yield get_line(matrix, (i, 0), (1, 1))
    yield get_line(matrix, (0, 0), (1, 1))
    for j in range(1, N):
        yield get_line(matrix, (0, j), (1, 1))


def get_max(matrix, el):
    m = 0

    for line in iter_horizontal(matrix):
        m = max(m, get_max_in_line(line, el))

    for line in iter_vertical(matrix):
        m = max(m, get_max_in_line(line, el))

    for line in iter_slash(matrix):
        m = max(m, get_max_in_line(line, el))

    for line in iter_backslash(matrix):
        m = max(m, get_max_in_line(line, el))

    return m

def handle(line):
    N = len(line)
    res = ['.'] * N
    current = N - 1
    for i in range(N - 1, -1, -1):
        if line[i] != '.':
            res[current] = line[i]
            current -= 1
    return res

def rotate(matrix):
    res = []
    for line in matrix:
        res.append(handle(line))
    return res

def handle_case(case_num):
    N, K = map(int, sys.stdin.readline().split())
    matrix = read_matrix(N)
    rotated_matrix = rotate(matrix)
    max_r = get_max(rotated_matrix, 'R')
    max_b = get_max(rotated_matrix, 'B')

    if max_r >= K:
        if max_b >= K:
            res = 'Both'
        else:
            res = 'Red'
    else:
        if max_b >= K:
            res = 'Blue'
        else:
            res = 'Neither'
    
    print 'Case #%s: %s' % (case_num, res)


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()