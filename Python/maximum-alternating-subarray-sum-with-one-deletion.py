# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maxAlternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = float("-inf")
        dp = [[float("-inf")]*2 for _ in xrange(2)]
        for x in nums:
            dp[1][:] = [max(dp[1][1]+x, dp[0][0]), max(dp[1][0]-x, dp[0][1])]
            dp[0][:] = [max(dp[0][1], 0)+x, dp[0][0]-x]
            result = max(result, max(dp[0]), max(dp[1]))
        return result
