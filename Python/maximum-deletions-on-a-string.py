# Time:  O(n^2)
# Space: O(n^2)

# dp
class Solution(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        if all(x == s[0] for x in s):
            return len(s)
        dp = [[0]*(len(s)+1) for i in xrange(len(s)+1)]  # dp[i][j]: max prefix length of s[i:] and s[j:]
        dp2 = [1]*len(s)  # dp2[i]: max operation count of s[i:]
        for i in reversed(xrange(len(s)-1)):
            for j in xrange(i+1, len(s)):
                if s[j] == s[i]:
                    dp[i][j] = dp[i+1][j+1]+1
                if dp[i][j] >= j-i:
                    dp2[i] = max(dp2[i], dp2[j]+1)
        return dp2[0]
