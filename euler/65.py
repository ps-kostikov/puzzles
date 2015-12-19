def coef(index):
    if index == 1:
        return 2
    if index % 3 == 0:
        return 2 * index / 3
    return 1

n = 100

numerator = coef(n)
denominator = 1

for index in range(n - 1, 0, -1):
    c = coef(index)
    n = denominator + c * numerator
    d = numerator
    numerator = n
    denominator = d

def GCD(a, b):
    max_ = max(a, b)
    min_ = min(a, b)
    if min_ == 0:
        return 0
    if max_ % min_ == 0:
        return min_
    return GCD(min_, max_ - min_ * (max_ / min_))

# print numerator, '/', denominator
# print GCD(numerator, denominator)
print sum(map(int, str(numerator)))