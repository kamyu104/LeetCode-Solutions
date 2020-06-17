# Time:  O(n)
# Space: O(1)

class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in xrange(len(nums)-1):
            nums[i+1] += nums[i]
        return nums
