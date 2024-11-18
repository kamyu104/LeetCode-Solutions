# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums[i] != nums[i+1] for i in xrange(len(nums)-1))
