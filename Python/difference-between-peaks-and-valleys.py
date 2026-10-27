# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def peakValleyDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums[i] for i in xrange(1, len(nums)-1) if nums[i-1] < nums[i] > nums[i+1])-sum(nums[i] for i in xrange(1, len(nums)-1) if nums[i-1] > nums[i] < nums[i+1])
