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
            return self.maxUnlimitPairProfit(prices)

        return self.maxAtMostKPairsProfit(prices, k)
    
    def maxUnlimitPairProfit(self, prices):
        profit = 0
        for i in xrange(len(prices) - 1):
            profit += max(0, prices[i + 1] - prices[i])     
        return profit
        
    def maxAtMostKPairsProfit(self, prices, k):
        if k == 0:
            return 0
            
        k_sum = [float("-inf") for _ in xrange(2 * k)]
        for i in xrange(1, len(k_sum), 2):
            k_sum[i] = 0
            
        for i in xrange(len(prices)):
            j, sign, pre_k_sum = 0, -1, 0
            while j < len(k_sum):
                diff = pre_k_sum + sign * prices[i]
                pre_k_sum, k_sum[j] = k_sum[j], max(diff, k_sum[j])
                j, sign = j + 1, sign * -1
                
        return k_sum[-1]

if __name__ == "__main__":
    print Solution().maxAtMostKPairsProfit([1, 2, 3, 4], 2)
