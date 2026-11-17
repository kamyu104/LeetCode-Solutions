# Time:  O(n + k)
# Space: O(k)

# dp
class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [0]*k
        for x in nums:
            dp[x%k] = max(dp[x%k], dp[-(x%k)%k]+1)                    
        return max(dp)
