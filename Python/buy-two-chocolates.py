# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def buyChoco(self, prices, money):
        """
        :type prices: List[int]
        :type money: int
        :rtype: int
        """
        i = min(xrange(len(prices)), key=lambda x: prices[x])
        j = min((j for j in xrange(len(prices)) if j != i), key=lambda x: prices[x])
        return money-(prices[i]+prices[j]) if prices[i]+prices[j] <= money else money
