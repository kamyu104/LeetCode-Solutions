# Time:  O(n)
# Space: O(1)

# dp, mono stack
class Solution(object):
    def minCost(self, nums, costs):
        """
        :type nums: List[int]
        :type costs: List[int]
        :rtype: int
        """
        stk1, stk2 = [], []
        dp = [float("inf")]*len(nums)
        dp[0] = 0
        for i in xrange(len(nums)):
            while stk1 and nums[stk1[-1]] <= nums[i]:
                dp[i] = min(dp[i], dp[stk1.pop()]+costs[i])
            stk1.append(i)
            while stk2 and nums[stk2[-1]] > nums[i]:
                dp[i] = min(dp[i], dp[stk2.pop()]+costs[i])
            stk2.append(i)
        return dp[-1]
