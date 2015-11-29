import sys


vowels = ['a', 'e', 'i', 'o', 'u']

def ruller(country):
	if country.lower().endswith('y'):
		return 'nobody'
	for vowel in vowels:
		if country.lower().endswith(vowel):
			return 'a queen'
	return 'a king'

def main():

	num = int(sys.stdin.readline())

	for i in range(num):
		country = sys.stdin.readline().strip()
		print 'Case #%s: %s is ruled by %s.' % (
				i + 1, country, ruller(country))


if __name__ == '__main__':
	main()