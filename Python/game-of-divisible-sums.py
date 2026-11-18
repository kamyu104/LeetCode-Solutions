# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maxDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp1, dp2 = nums[-1], 0
        for i in reversed(xrange(len(nums)-1)):
            dp1, dp2 = max(nums[i]+(dp1 if nums[i]%3 else -dp1), (nums[i]+nums[i+1])+(dp2 if (nums[i]+nums[i+1])%3 else -dp2)), dp1
        return dp1
