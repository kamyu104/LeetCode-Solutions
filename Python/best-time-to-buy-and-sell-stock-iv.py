# Time:  O(k * n)
# Space: O(k)
#
# Say you have an array for which the ith element is the price of a given stock on day i.
# 
# Design an algorithm to find the maximum profit. You may complete at most k transactions.
# 
# Note:
# You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
#

class Solution:
    # @return an integer as the maximum profit 
    def maxProfit(self, k, prices):
        if k >= len(prices) / 2:
            return self.maxAtMostNPairsProfit(prices)

        return self.maxAtMostKPairsProfit(prices, k)

    def maxAtMostNPairsProfit(self, prices):
        profit = 0
        for i in xrange(len(prices) - 1):
            profit += max(0, prices[i + 1] - prices[i])     
        return profit

    def maxAtMostKPairsProfit(self, prices, k):
        max_buy = [float("-inf") for _ in xrange(k + 1)]
        max_sell = [0 for _ in xrange(k + 1)]

        for i in xrange(len(prices)):
            for j in xrange(1, min(k, i/2+1) + 1):
                max_buy[j] = max(max_buy[j], max_sell[j-1] - prices[i])
                max_sell[j] = max(max_sell[j], max_buy[j] + prices[i])

        return max_sell[k]

if __name__ == "__main__":
    print Solution().maxAtMostKPairsProfit([1, 2, 3, 4], 2)
