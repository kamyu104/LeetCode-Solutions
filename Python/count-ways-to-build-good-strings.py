# Time:  O(n)
# Space: O(n)

# dp
class Solution(object):
    def countGoodStrings(self, low, high, zero, one):
        """
        :type low: int
        :type high: int
        :type zero: int
        :type one: int
        :rtype: int
        """
        MOD = 10**9+7
        result = 0
        dp = [0]*(high+1)
        dp[0] = 1
        for i in xrange(1, high+1):
            if i >= zero:
                dp[i] = (dp[i]+dp[i-zero])%MOD
            if i >= one:
                dp[i] = (dp[i]+dp[i-one])%MOD
            if i >= low:
                result = (result+dp[i])%MOD
        return result
