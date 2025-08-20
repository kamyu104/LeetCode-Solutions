# Time:  O(n + k)
# Space: O(k)

# dp, prefix sum
class Solution(object):
    def minArraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [float("inf")]*k
        dp[0] = result = 0
        for x in nums:
            result += x
            dp[result%k] = result = min(result, dp[result%k])
        return result
