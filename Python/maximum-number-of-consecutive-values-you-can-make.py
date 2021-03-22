# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def getMaximumConsecutive(self, coins):
        """
        :type coins: List[int]
        :rtype: int
        """
        coins.sort()
        result = 1
        for c in coins:
            if c > result:
                break
            result += c
        return result
