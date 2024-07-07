# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maximumPoints(self, enemyEnergies, currentEnergy):
        """
        :type enemyEnergies: List[int]
        :type currentEnergy: int
        :rtype: int
        """
        mn = min(enemyEnergies)
        return ((currentEnergy-mn)+sum(enemyEnergies))//mn if currentEnergy >= mn else 0
