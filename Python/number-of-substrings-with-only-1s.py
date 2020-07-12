# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9+7
        result, count = 0, 0
        for c in s:
            count = count+1 if c == '1' else 0
            result = (result+count)%MOD
        return result
