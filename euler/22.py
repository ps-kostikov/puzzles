def value(word):
    def char_value(c):
        return ord(c) - ord('a') + 1

    return sum(map(char_value, word.lower()))

data = open('22.in').read()
words = map(lambda s: s.strip('"'), data.split(','))

print sum(
    (index + 1) * value(word)
    for index, word in enumerate(sorted(words))
)
# print value("COLIN")