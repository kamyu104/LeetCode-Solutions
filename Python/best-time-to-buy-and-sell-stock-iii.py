# Time:  O(n)
# Space: O(1)
#
# Say you have an array for which the ith element 
# is the price of a given stock on day i.
#
# Design an algorithm to find the maximum profit. 
# You may complete at most two transactions.
#
# Note:
# You may not engage in multiple transactions at the same time 
# (ie, you must sell the stock before you buy again).
#

# Time:  O(n)
# Space: O(1)
class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        hold1, hold2 = float("-inf"), float("-inf")
        release1, release2 = 0, 0
        for i in prices:
            release2 = max(release2, hold2 + i)
            hold2    = max(hold2,    release1 - i)
            release1 = max(release1, hold1 + i)
            hold1    = max(hold1,    -i);
        return release2
    
# Time:  O(k^2 * n)
# Space: O(k)
class Solution2:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        return self.maxAtMostKPairsProfit(prices, 2)
        
    def maxAtMostKPairsProfit(self, prices, k):
        max_buy = [float("-inf") for _ in xrange(k + 1)]
        max_sell = [0 for _ in xrange(k + 1)]

        for i in xrange(len(prices)):
            j = 1
            while j <= k and j <= i + 1:
                max_buy[j] = max(max_buy[j], max_sell[j-1] - prices[i])
                max_sell[j] = max(max_sell[j], max_buy[j] + prices[i])
                j += 1

        return max_sell[k]

# Time:  O(n)
# Space: O(n)     
class Solution3:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        min_price, max_profit_from_left, max_profits_from_left = float("inf"), 0, []
        for price in prices:
            min_price = min(min_price, price)
            max_profit_from_left = max(max_profit_from_left, price - min_price)
            max_profits_from_left.append(max_profit_from_left)
            
        max_price, max_profit_from_right, max_profits_from_right = 0, 0, []
        for i in reversed(range(len(prices))):
            max_price = max(max_price, prices[i])
            max_profit_from_right = max(max_profit_from_right, max_price - prices[i])
            max_profits_from_right.insert(0, max_profit_from_right)
            
        max_profit = 0
        for i in range(len(prices)):
            max_profit = max(max_profit, max_profits_from_left[i] + max_profits_from_right[i])
        
        return max_profit
        
if __name__ == "__main__":
    result = Solution().maxProfit([3, 2, 1, 4, 2, 5, 6])
    print result
