# Time:  O(n + m)
# Space: O(1)

# dp
class Solution(object):
    def canMakeSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dp = [0]*2
        for x in t:
            if s[dp[1]] == x:
                dp[1] += 1
            dp[1] = max(dp[1], dp[0]+1)
            if dp[1] == len(s):
                return True
            if s[dp[0]] == x:
                dp[0] += 1
        return False
