min_, max_ = 2, 100
l = [
    a ** b
    for a in range(min_, max_ + 1)
    for b in range(min_, max_ + 1)
]
print(len(set(l)))