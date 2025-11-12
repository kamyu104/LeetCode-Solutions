# Time:  O(n * k)
# Space: O(k)

# dp
class Solution(object):
    def maximumProfit(self, prices, k):
        """
        :type prices: List[int]
        :type k: int
        :rtype: int
        """
        dp = [0]*(len(prices)+1)
        result = 0
        for i in xrange(k):
            x, y = float("-inf"), float("-inf")
            new_dp = [float("-inf")]*(len(prices)+1)
            for j in xrange(i, len(prices)):
                x, y = max(x, dp[j]-prices[j]), max(y, dp[j]+prices[j])
                new_dp[j+1] = max(new_dp[j], x+prices[j], y-prices[j])
            dp = new_dp
            result = max(result, dp[-1])
        return result


# Time:  O(n * k)
# Space: O(k)
# dp
class Solution2(object):
    def maximumProfit(self, prices, k):
        """
        :type prices: List[int]
        :type k: int
        :rtype: int
        """
        bought = [float("-inf")]*k
        sold = [float("-inf")]*k
        result = [float("-inf")]*(k+1)
        result[0] = 0
        for x in prices:
            for i in reversed(xrange(k)):
                result[i+1] = max(result[i+1], bought[i]+x, sold[i]-x)
                bought[i] = max(bought[i], result[i]-x)
                sold[i] = max(sold[i], result[i]+x)
        return max(result)
