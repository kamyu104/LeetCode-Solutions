# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minimumMoves(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = i = 0
        while i < len(s):
            if s[i] == 'X':
                result += 1
                i += 3
            else:
                i += 1
        return result
