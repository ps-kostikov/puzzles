def sum_digits(n, base=10):
    sum = 0
    while n:
        sum += n % base
        n /= base
    return sum

print(sum_digits(2 ** 1000))
