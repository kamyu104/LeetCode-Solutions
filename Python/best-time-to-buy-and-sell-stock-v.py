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
