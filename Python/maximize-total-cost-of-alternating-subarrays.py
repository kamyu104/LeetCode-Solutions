# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maximumTotalCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [nums[0], float("-inf")]
        for i in xrange(1, len(nums)):
            dp[:] = [max(dp)+nums[i], dp[0]-nums[i]]
        return max(dp)
