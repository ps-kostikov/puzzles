prev = 1
current = 1
index = 2
limit = 10 ** (1000 - 1)
while True:
    next_ = prev + current
    prev = current
    current = next_
    index += 1
    # print index, ":", current
    if current >= limit:
        print(index)
        break