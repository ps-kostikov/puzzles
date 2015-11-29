import sys

from collections import defaultdict

def append_folowers(result, monk, folowers, limit):
    if not limit:
        return
    for folower in folowers[monk]:
        result.add(folower)
        append_folowers(result, folower, folowers, limit-1)


def handle_case(case_num):
    N = int(sys.stdin.readline())
    folowers = defaultdict(list)
    next = [int(ss) for ss in sys.stdin.readline().split()]
    for i in range(1, N+1):
        folowers[next[i-1]].append(i)

    print "Case #%s:" % case_num
    for i in range(1, N+1):
        result = set()
        result.add(i)
        append_folowers(result, i, folowers, N+2)
        print "%s" % len(result)


def main():
    T = int(sys.stdin.readline())
    for case_num in range(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()