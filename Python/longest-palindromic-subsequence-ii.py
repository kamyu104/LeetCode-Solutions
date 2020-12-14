# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [[[0]*26 for _ in xrange(len(s))] for _ in xrange(len(s))]
        for i in reversed(xrange(len(s))):
            for j in xrange(i+1, len(s)):
                if i == j-1:
                    if s[j] == s[i]:
                        dp[i][j][ord(s[i])-ord('a')] = 2
                else:
                    for k in xrange(26):
                        if s[j] == s[i] and ord(s[j])-ord('a') != k:
                            dp[i][j][ord(s[j])-ord('a')] = max(dp[i][j][ord(s[j])-ord('a')], dp[i+1][j-1][k]+2);
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k], dp[i+1][j][k], dp[i+1][j-1][k])
        return max(dp[0][-1])
