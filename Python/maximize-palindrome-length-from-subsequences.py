# Time:  O((m + n)^2)
# Space: O((m + n)^2)

class Solution(object):
    def longestPalindrome(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        s = word1+word2
        dp = [[0]*len(s) for _ in xrange(len(s))]
        result = 0
        for j in xrange(len(s)):
            dp[j][j] = 1
            for i in reversed(xrange(j)):
                if s[i] == s[j]:
                    dp[i][j] = 2 if i+1 == j else dp[i+1][j-1] + 2
                    if i < len(word1) <= j:
                        result = max(result, dp[i][j])
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return result


# Time:  O((m + n)^2)
# Space: O((m + n)^2)
class Solution2(object):
    def longestPalindrome(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        s = word1+word2
        dp = [[0]*len(s) for _ in xrange(len(s))]
        for j in xrange(len(s)):
            dp[j][j] = 1
            for i in reversed(xrange(j)):
                if s[i] == s[j]:
                    dp[i][j] = 2 if i+1 == j else dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return max([dp[i][j] for i in xrange(len(word1)) for j in xrange(len(word1), len(s)) if s[i] == s[j]] or [0])
