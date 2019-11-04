# Time:  O(m * n)
# Space: O(min(m, n))

class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        if len(text1) < len(text2):
            return self.longestCommonSubsequence(text2, text1)

        dp = [[0 for _ in xrange(len(text2)+1)] for _ in xrange(2)]
        for i in xrange(1, len(text1)+1):
            for j in xrange(1, len(text2)+1):
                dp[i%2][j] = dp[(i-1)%2][j-1]+1 if text1[i-1] == text2[j-1] \
                             else max(dp[(i-1)%2][j], dp[i%2][j-1])
        return dp[len(text1)%2][len(text2)]
