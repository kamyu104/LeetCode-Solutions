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
        dp = {0: arr1[0], 1: arr2[0]}  # dp[min_cost] = end_with_val
        for i in xrange(1, len(arr1)):
            next_dp = collections.defaultdict(lambda: float("inf"))
            for j in dp.iterkeys():
                if dp[j] < arr1[i]:
                    next_dp[j] = min(next_dp[j], arr1[i])
                k = bisect.bisect_right(arr2, dp[j])
                if k == len(arr2):
                    continue
                next_dp[j+1] = min(next_dp[j+1], arr2[k])
            dp = next_dp
            if not dp:
                return -1
        return min(dp.iterkeys())
