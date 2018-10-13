# Time:  O(n)
# Space: O(1)


class Solution(object):
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        profit = 0
        for i in xrange(len(prices) - 1):
            profit += max(0, prices[i + 1] - prices[i])
        return profit

    def maxProfit2(self, prices):
        return sum(map(lambda x: max(prices[x + 1] - prices[x], 0),
                       xrange(len(prices[:-1]))))

