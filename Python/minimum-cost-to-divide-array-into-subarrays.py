# Time:  O(n^2)
# Space: O(n)

# prefix sum, dp
class Solution(object):
    def minimumCost(self, nums, cost, k):
        """
        :type nums: List[int]
        :type cost: List[int]
        :type k: int
        :rtype: int
        """
        prefix1 = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix1[i+1] = prefix1[i]+nums[i]
        prefix2 = [0]*(len(cost)+1)
        for i in xrange(len(nums)):
            prefix2[i+1] = prefix2[i]+cost[i]
        dp = [float("inf")]*(len(nums)+1)
        dp[-1] = 0
        for i in reversed(xrange(len(nums))):
            for j in xrange(i, len(nums)):
                dp[i] = min(dp[i], prefix1[j+1]*(prefix2[j+1]-prefix2[i])+dp[j+1]+(k*(prefix2[-1]-prefix2[i])))
        return dp[0]
