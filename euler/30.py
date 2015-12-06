def f(n):
    return sum(map(lambda c: int(c) ** 5, str(n)))

nums = [
    n
    for n in range(2, 9 ** 5 * 6)
    if n == f(n)
]
print(nums)
print(sum(nums))