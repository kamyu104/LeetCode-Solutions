# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def minimumTime(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, dp = len(s), 0
        for i, c in enumerate(s):
            dp = min(dp+2*(c == '1'), i+1)
            result = min(result, dp+((len(s)-1)-i))
        return result
