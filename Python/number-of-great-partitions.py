# Time:  O(n * k)
# Space: O(k)

# knapsack dp
class Solution(object):
    def countPartitions(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        if sum(nums) < 2*k:
            return 0
        dp = [0]*k
        dp[0] = 1
        for x in nums:
            for i in reversed(xrange(k-x)):
                dp[i+x] = (dp[i+x]+dp[i])%MOD
        return (pow(2, len(nums), MOD)-2*reduce(lambda total, x: (total+x)%MOD, dp, 0))%MOD
