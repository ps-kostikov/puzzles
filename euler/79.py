import sys
import itertools


input_list = list(set(sys.stdin.read().split()))

distinct_digits = sorted(list(set(''.join(input_list))))

def match(passwd, key):
    index = 0
    for p in passwd:
        if p == key[index]:
            index += 1
            if index == len(key):
                return True

    return False

def match_all(passwd):
    return all([match(passwd, key) for key in input_list])


for p in itertools.permutations(distinct_digits):
    s = ''.join(p)
    if match_all(s):
        print s
        break
