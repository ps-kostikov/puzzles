import sys

def decode(encoded, key):
    return [
        ord(key[i % len(key)]) ^ c
        for i, c in enumerate(encoded)
    ]

def test(text):
    return all([
        'and' in text.lower(),
        'the' in text.lower(),
        'have' in text.lower()
    ])

encoded = map(int, sys.stdin.read().strip().split(','))

to_letter = lambda x: chr(ord('a') + x)

for fst in range(26):
    for snd in range(26):
        for thd in range(26):
            key = to_letter(fst) + to_letter(snd) + to_letter(thd)
            decoded = decode(encoded, key)

            text = ''.join(map(chr, decoded))
            if test(text):
                print sum(decoded)
                # print key
                # print text
                sys.exit(0)

