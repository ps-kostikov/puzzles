import sys

class Translator:
    def __init__(self, samples):
        self.__dict = {}
        self.__dict['z'] = 'q'
        self.__dict['q'] = 'z'
        for sample in samples:
            s = sample[0]
            t = sample[1]
            assert (len(s) == len(t))
            for (sw, tw) in zip(s, t):
                if sw == ' ':
                    assert tw == ' '
                    continue
                if self.__dict.has_key(sw):
                    assert self.__dict[sw] == tw
                else:
                    self.__dict[sw] = tw

        # print self.__dict
        # print len(self.__dict.keys())

        # values = self.__dict.values()
        # values.sort()
        # print "values = %s" % values

        # keys = self.__dict.keys()
        # keys.sort()
        # print "keys = %s" % keys

    def translate_word(self, word):
        return ''.join([self.__dict[letter] for letter in word])

    def translate_sentence(self, sentence):
        return ' '.join([self.translate_word(word) for word in sentence.split()])


def get_samples():
    inp = open('samples.txt')
    samples = []
    for ss in inp:
        ss = ss.strip()
        # print ss
        samples.append(ss.split('\t'))
    return samples

if __name__ == '__main__':
    # print 'hello'

    translator = Translator(get_samples())

    test_number = int(sys.stdin.readline())
    for test_index in range(test_number):
        sentence = sys.stdin.readline().strip()
        translation = translator.translate_sentence(sentence)
        print 'Case #%s: %s' % (test_index + 1, translation)