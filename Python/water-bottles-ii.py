# Time:  O(sqrt(n))
# Space: O(1)

# simulation
class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        result = numBottles
        while numBottles >= numExchange:
            numBottles -= numExchange
            numExchange += 1
            result += 1
            numBottles += 1
        return result
