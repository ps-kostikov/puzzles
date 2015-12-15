def reverse(n):
    return int(str(n)[::-1])

def is_palindrom(n):
    return n == reverse(n)

def is_lychrel(n):
    current = n
    for i in range(50):
        current = current + reverse(current)
        if is_palindrom(current):
            return False
    return True

print(len([i for i in range(1, 10000) if is_lychrel(i)]))
