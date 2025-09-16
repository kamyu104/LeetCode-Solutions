# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def smallestAbsent(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        lookup = set(nums)
        return next(x for x in xrange(max(total//len(nums)+1, 1), max(max(nums)+1, 1)+1) if x not in lookup and x*len(nums) > total)
