# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def countStableSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        dp = [[0]*2 for _ in xrange(2)]  # dp[p][i]: count of subsequences that end with exactly (i+1) consecutive numbers of parity p
        for x in nums:
            p = x%2
            dp[p][1] = (dp[p][1]+dp[p][0])%MOD
            dp[p][0] = (dp[p][0]+1+dp[1^p][0]+dp[1^p][1])%MOD
        return sum(dp[p][i] for p in xrange(2) for i in xrange(2))%MOD
