# Time:  O(n^2 * logn)
# Space: O(n)

import collections
import bisect


class Solution(object):
    def makeArrayIncreasing(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        arr2 = sorted(set(arr2))
        dp = {0: -1}  # dp[min_cost] = end_with_val
        for val1 in arr1:
            next_dp = collections.defaultdict(lambda: float("inf"))
            for cost, val in dp.iteritems():
                if val < val1:
                    next_dp[cost] = min(next_dp[cost], val1)
                k = bisect.bisect_right(arr2, val)
                if k == len(arr2):
                    continue
                next_dp[cost+1] = min(next_dp[cost+1], arr2[k])
            dp = next_dp
            if not dp:
                return -1
        return min(dp.iterkeys())
