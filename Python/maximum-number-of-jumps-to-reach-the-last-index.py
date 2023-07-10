# Time:  O(n^2)
# Space: O(n)

# dp
class Solution(object):
    def maximumJumps(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [-1]*len(nums)
        dp[0] = 0
        for i in xrange(1, len(nums)):
            for j in xrange(i):
                if abs(nums[i]-nums[j]) <= target:
                    if dp[j] != -1:
                        dp[i] = max(dp[i], dp[j]+1)
        return dp[-1]
