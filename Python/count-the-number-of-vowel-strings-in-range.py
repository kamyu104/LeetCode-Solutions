# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def vowelStrings(self, words, left, right):
        """
        :type words: List[str]
        :type left: int
        :type right: int
        :rtype: int
        """
        VOWELS = {'a', 'e', 'i', 'o', 'u'}
        return sum(words[i][0] in VOWELS and words[i][-1] in VOWELS for i in xrange(left, right+1))
