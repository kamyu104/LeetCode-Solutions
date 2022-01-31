# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def findFinalValue(self, nums, original):
        """
        :type nums: List[int]
        :type original: int
        :rtype: int
        """
        lookup = set(nums)
        while original in lookup:
            original *= 2
        return original
