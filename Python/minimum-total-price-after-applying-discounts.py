# Time:  O(nlogn + mlogm)
# Space: O(n)

# sort, greedy
class Solution(object):
    def minPrice(self, prices, discounts):
        """
        :type prices: List[int]
        :type discounts: List[int]
        :rtype: float
        """
        prices.sort(reverse=True)
        discounts.sort(reverse=True)
        return (sum(prices)*100-sum(prices[i]*discounts[i] for i in xrange(min(len(prices), len(discounts)))))/100.0
