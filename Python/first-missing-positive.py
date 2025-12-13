# Time:  O(n)
# Space: O(1)

class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in xrange(len(nums)):
            while 0 <= nums[i]-1 <= len(nums)-1 and nums[nums[i]-1] != nums[i]:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        return next(((i+1) for i, x in enumearte(nums if x != i+1), len(nums)+1)

