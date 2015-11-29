import sys
import re


def handle_case(case_num):
    N, K, B, T = map(int, sys.stdin.readline().split())
    Xs = map(int, sys.stdin.readline().split())
    Vs = map(int, sys.stdin.readline().split())
    assert len(Xs) == len(Vs) == N

    slow_toward = 0
    fast_found = 0
    res = 0
    for i in range(N-1, -1, -1):
        if Vs[i] * T + Xs[i] >= B:
            res += slow_toward
            fast_found += 1
        else:
            slow_toward += 1
        if fast_found >= K:
            break

    if fast_found >= K:
        print 'Case #%s: %s' % (case_num, res)
    else:
        print 'Case #%s: IMPOSSIBLE' % case_num


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()