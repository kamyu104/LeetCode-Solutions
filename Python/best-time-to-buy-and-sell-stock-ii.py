# Time:  O(n)
# Space: O(1)
#
# Say you have an array for which the ith element is 
# the price of a given stock on day i.
#
# Design an algorithm to find the maximum profit. 
# You may complete as many transactions as you like 
# (ie, buy one and sell one share of the stock multiple times). 
# However, you may not engage in multiple transactions at the same time 
# (ie, you must sell the stock before you buy again).
#

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        profit = 0
        for i in xrange(len(prices) - 1):
            profit += max(0, prices[i + 1] - prices[i])     
        return profit

if __name__ == "__main__":
    result = Solution().maxProfit([3, 2, 1, 4, 2, 5, 6])
    print result
    
