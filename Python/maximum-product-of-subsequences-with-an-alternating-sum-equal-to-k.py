# Time:  O(n * k * l), l = limits
# Space: O(n * k * l)

import collections


# dp
class Solution(object):
    def maxProduct(self, nums, k, limit):
        """
        :type nums: List[int]
        :type k: int
        :type limit: int
        :rtype: int
        """
        total = sum(nums)
        if k > total or k < -total:  # optimized to speed up
            return -1
        dp = collections.defaultdict(set)
        for x in nums:
            new_dp = collections.defaultdict(set, {k:set(v) for k, v in dp.iteritems()})
            new_dp[(1, x)].add(min(x, limit+1))
            for (p, total), products in dp.iteritems():
                new_state = (p^1, total+(x if p == 0 else -x))
                for v in products:
                    new_dp[new_state].add(min(v*x, limit+1))
            dp = new_dp
        result = -1
        for (p, total), products in dp.iteritems():
            if total != k:
                continue
            for v in products:
                if v <= limit:
                    result = max(result, v)
        return result
