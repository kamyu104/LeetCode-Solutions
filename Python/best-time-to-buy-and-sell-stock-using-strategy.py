# Time:  O(n)
# Space: O(1)

# two pointers, sliding window
class Solution(object):
    def maxProfit(self, prices, strategy, k):
        """
        :type prices: List[int]
        :type strategy: List[int]
        :type k: int
        :rtype: int
        """
        result = curr = 0
        for i in xrange(len(prices)):
            curr += prices[i]*(0 if i < k//2 else 1) if i < k else prices[i]*strategy[i]
            result += prices[i]*strategy[i]
        result = max(result, curr)
        for i in xrange(k, len(prices)):
            curr += (prices[i-k]*strategy[i-k])+(prices[i]-prices[i-k//2])-(prices[i]*strategy[i])
            result = max(result, curr)
        return result
