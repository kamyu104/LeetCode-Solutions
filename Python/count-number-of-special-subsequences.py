# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countSpecialSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*3
        for x in nums:
            dp[x] = ((dp[x]+dp[x])%MOD+(dp[x-1] if x-1 >= 0 else 1))%MOD
        return dp[-1]
