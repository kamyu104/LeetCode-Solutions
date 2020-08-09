# Time:  O(10 * n)
# Space: O(1024)

class Solution(object):
    def longestAwesome(self, s):
        """
        :type s: str
        :rtype: int
        """
        ALPHABET_SIZE = 10
        result, mask, lookup = 0, 0, [len(s)]*(2**ALPHABET_SIZE)
        lookup[0] = -1
        for i, ch in enumerate(s):
            mask ^= 2**(ord(ch)-ord('0'))
            if lookup[mask] == len(s):
                lookup[mask] = i
            result = max(result, i - lookup[mask])
            for d in xrange(ALPHABET_SIZE):
                result = max(result, i - lookup[mask^(2**d)])
        return result
