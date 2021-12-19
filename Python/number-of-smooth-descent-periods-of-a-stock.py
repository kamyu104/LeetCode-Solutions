# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getDescentPeriods(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        result = l = 0
        for i in xrange(len(prices)):
            l += 1
            if i+1 == len(prices) or prices[i]-1 != prices[i+1]:
                result += l*(l+1)//2
                l = 0
        return result
