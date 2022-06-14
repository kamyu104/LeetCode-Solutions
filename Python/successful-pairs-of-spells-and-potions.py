# Time:  O(mlogm + nlogm)
# Space: O(1)

# binary search
class Solution(object):
    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """
        def ceil_divide(a, b):
            return (a+(b-1))//b
            
        potions.sort()
        return [len(potions)-bisect.bisect_left(potions, ceil_divide(success, s)) for s in spells]
