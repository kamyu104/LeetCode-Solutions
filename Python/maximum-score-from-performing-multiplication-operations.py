# Time:  O(m^2)
# Space: O(m)

class Solution(object):
    def maximumScore(self, nums, multipliers):
        """
        :type nums: List[int]
        :type multipliers: List[int]
        :rtype: int
        """
        dp = [0]*(len(multipliers)+1)
        for l, m in enumerate(reversed(multipliers), start=len(nums)-len(multipliers)):
            dp = [max(m*nums[i]+dp[i+1], m*nums[i+l]+dp[i]) for i in xrange(len(dp)-1)]
        return dp[0]
