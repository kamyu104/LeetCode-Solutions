# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def alternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums[i] for i in xrange(0, len(nums), 2))-sum(nums[i] for i in xrange(1, len(nums), 2))
