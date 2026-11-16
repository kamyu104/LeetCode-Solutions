# Time:  O(n)
# Space: O(1)

# string, dp
class Solution(object):
    def countValidSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        dp = [-1]*3
        for i, x in enumerate(s):
            if x == 'a':
                dp[0] = i
            elif x == 'b':
                dp[1] = dp[0]
            elif x == 'c':
                dp[2] = dp[1]
            result += i-dp[2]
        return result
