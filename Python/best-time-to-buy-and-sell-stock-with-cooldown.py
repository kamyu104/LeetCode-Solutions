# Time:  O(n)
# Space: O(1)

# Say you have an array for which the ith element is the price of a given stock on day i.
#
# Design an algorithm to find the maximum profit. You may complete as
# many transactions as you like (ie, buy one and sell one share of the
# stock multiple times) with the following restrictions:
#
# You may not engage in multiple transactions at the same time
# (ie, you must sell the stock before you buy again).
# After you sell your stock, you cannot buy stock on next day.
# (ie, cooldown 1 day)
# Example:
#
# prices = [1, 2, 3, 0, 2]
# maxProfit = 3
# transactions = [buy, sell, cooldown, buy, sell]
#

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        buy, sell, coolDown = [0] * 2, [0] * 2, [0] * 2
        buy[0] = -prices[0]
        for i in xrange(1, len(prices)):
            # Bought before or buy today.
            buy[i % 2] = max(buy[(i - 1) % 2], coolDown[(i - 1) % 2] - prices[i])
            # Sell today.
            sell[i % 2] = buy[(i - 1) % 2] + prices[i]
            # Sold before yesterday or sold yesterday.
            coolDown[i % 2] = max(coolDown[(i - 1) % 2], sell[(i - 1) % 2])
        return max(coolDown[(len(prices) - 1) % 2], sell[(len(prices) - 1) % 2])
