# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxAlternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = nums[0]
        for i in xrange(len(nums)-1):
            result += max(nums[i+1]-nums[i], 0)
        return result
