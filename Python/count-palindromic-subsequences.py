# Time:  O(10^(l/2) * n * l), l = 5
# Space: O(l)

# dp
class Solution(object):
    def countPalindromes(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9+7
        result = 0
        for i in xrange(10):
            for j in xrange(10):
                pattern = "%s%s*%s%s" % (i, j, j, i)
                dp = [0]*(5+1)
                dp[0] = 1
                for k in xrange(len(s)):
                    for l in reversed(xrange(5)):
                        if pattern[l] == '*' or pattern[l] == s[k]:
                            dp[l+1] = (dp[l+1]+dp[l])%MOD
                result = (result+dp[5])%MOD
        return result
