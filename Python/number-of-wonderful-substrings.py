# Time:  O(n)
# Space: O(2^10)

class Solution(object):
    def wonderfulSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        ALPHABET_SIZE = 10
        count = [0]*(2**ALPHABET_SIZE)
        count[0] = 1
        result = curr = 0
        for c in word:
            curr ^= 1<<(ord(c)-ord('a'))
            result += count[curr]
            result += sum(count[curr^(1<<i)] for i in xrange(ALPHABET_SIZE))
            count[curr] += 1
        return result
