# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minimumPrefixLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return next((i+1 for i in reversed(xrange(len(nums)-1)) if not nums[i] < nums[i+1]), 0)
