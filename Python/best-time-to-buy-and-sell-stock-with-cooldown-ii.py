# Time:  O(n^2)
# Space: O(n)

# dp
class Solution(object):
    def maxProfit(self, prices, cooldown, costs):
        """
        :type prices: List[int]
        :type cooldown: int
        :type costs: List[int]
        :rtype: int
        """
        dp = [0]*(len(prices)+1)
        for j in xrange(len(prices)):
            mx = dp[j]
            for i in xrange(j):
                mx = max(mx, dp[max((i+1)-(cooldown+1), 0)]+prices[j]-prices[i]-costs[j-i])
            dp[j+1] = mx
        return dp[-1]
