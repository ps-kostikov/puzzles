xn = 3
yn = 2
count = 0
for i in range(1, 1001):
    xn1, yn1 = 2 * yn + xn, yn + xn

    if len(str(xn1)) > len(str(yn1)):
        count += 1

    xn, yn = xn1, yn1

print(count)