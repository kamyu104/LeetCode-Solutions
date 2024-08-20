# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maxEnergyBoost(self, energyDrinkA, energyDrinkB):
        """
        :type energyDrinkA: List[int]
        :type energyDrinkB: List[int]
        :rtype: int
        """
        dp = [0]*2
        for i in xrange(len(energyDrinkA)):
            dp = [max(dp[0]+energyDrinkA[i], dp[1]), max(dp[1]+energyDrinkB[i], dp[0])]
        return max(dp)
