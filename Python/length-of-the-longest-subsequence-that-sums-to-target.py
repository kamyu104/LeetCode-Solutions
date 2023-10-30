# Time:  O(n * t)
# Space: O(t)

# knapsack dp
class Solution(object):
    def lengthOfLongestSubsequence(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [-1]*(target+1)
        dp[0] = 0
        for x in nums:
            for i in reversed(xrange(x, len(dp))):
                if dp[i-x] != -1:
                    dp[i] = max(dp[i], dp[i-x]+1)
        return dp[-1]
