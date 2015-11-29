import sys

def count(p, totals):
    good, strange, bad = 0, 0, 0
    for total in totals:
        rest = (total - p) / 2.
        if rest < 0:
            bad += 1
        elif rest >= p - 1:
            good += 1
        elif rest >= p - 2:
            strange += 1
        else:
            bad += 1
    return good, strange, bad

if __name__ == '__main__':

    test_number = int(sys.stdin.readline())
    for test_index in range(test_number):
        inputs = map(int, sys.stdin.readline().split())
        N = inputs[0]
        S = inputs[1]
        p = inputs[2]
        totals = inputs[3:]

        # print count(p, totals)
        (good, strange, bad) = count(p, totals)
        result = good + min(strange, S)
        print 'Case #%s: %s' % (test_index + 1, result)