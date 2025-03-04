# Time:  O(n^2)
# Space: O(n)

import collections


# dp, greedy
class Solution(object):
    def minCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = collections.defaultdict(lambda: float("inf"))
        dp[nums[0]] = 0
        for i in xrange(1, len(nums)-1, 2):
            new_dp = collections.defaultdict(lambda: float("inf"))
            x, y = nums[i], nums[i+1]
            for z, c in dp.iteritems():
                v = sorted([x, y, z])
                new_dp[v[0]] = min(new_dp[v[0]], c+v[2])
                new_dp[v[2]] = min(new_dp[v[2]], c+v[1])
            dp = new_dp
        last = nums[-1] if len(nums)%2 == 0 else 0
        return min(c+max(x, last) for x, c in dp.iteritems())
