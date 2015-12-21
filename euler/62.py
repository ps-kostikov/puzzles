import collections

def number_to_snapshot(number):
    return ''.join(sorted(str(number)))


snapshot_to_count = collections.defaultdict(int)

n = 1
while True:
    cube = n * n * n
    snapshot = number_to_snapshot(cube)
    snapshot_to_count[snapshot] += 1
    if snapshot_to_count[snapshot] == 5:
        target_snapshot = snapshot
        break
    n += 1

n = 1
while True:
    cube = n * n * n
    if number_to_snapshot(cube) == target_snapshot:
        print cube
        break
    n += 1
