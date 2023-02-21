# Time:  O(logr)
# Space: O(1)

# hash table, bit manipulations
class Solution(object):
    def minImpossibleOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lookup = set(nums)
        return next(1<<i for i in xrange(31) if 1<<i not in lookup)
