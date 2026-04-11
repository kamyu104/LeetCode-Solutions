# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def minIncrease(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = 0
        if len(nums)%2:
            for i in xrange(1, len(nums)-1, 2):
                dp += max((max(nums[i-1], nums[i+1])+1)-nums[i], 0)
            return dp
        dp2 = 0
        for i in xrange(1, len(nums)-1, 2):
            dp += max((max(nums[i-1], nums[i+1])+1)-nums[i], 0)
            dp2 += max((max(nums[i], nums[i+2])+1)-nums[i+1], 0)
            dp2 = min(dp2, dp)
        return dp2
