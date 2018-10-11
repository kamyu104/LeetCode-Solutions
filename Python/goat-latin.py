# Time:  O(n + w^2), n = w * l,
#                    n is the length of S,
#                    w is the number of word,
#                    l is the average length of word
# Space: O(n)

class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        def convert(S):
            vowel = set('aeiouAEIOU')
            for i, word in enumerate(S.split(), 1):
                if word[0] not in vowel:
                    word = word[1:] + word[:1]
                yield word + 'ma' + 'a'*i
        return " ".join(convert(S))

