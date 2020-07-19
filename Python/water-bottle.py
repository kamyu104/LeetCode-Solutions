# Time:  O(logn/logm), n is numBottles, m is numExchange
# Space: O(1)

class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        result = numBottles
        while numBottles >= numExchange:
            numBottles, remainder = divmod(numBottles, numExchange)
            result += numBottles
            numBottles += remainder
        return result
