# Time:  O(n^2)
# Space: O(n)

import collections


# dp
class Solution(object):
    def minCost(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [float("inf")]*(len(nums)+1)
        dp[0] = 0
        for i in xrange(len(dp)-1):
            cnt = [0]*len(nums)
            d = 0
            for j in xrange(i+1, len(dp)):
                cnt[nums[j-1]] += 1
                if cnt[nums[j-1]] == 1:
                    d += 1
                elif cnt[nums[j-1]] == 2:
                    d -= 1
                dp[j] = min(dp[j], dp[i]+k+((j-i)-d))
        return dp[-1]
