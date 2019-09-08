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
        arr2.sort()
        dp = {-1:0}
        for i in arr1:
            next_dp = collections.defaultdict(lambda: float("inf"))
            for j in dp.iterkeys():
                if i > j:
                    next_dp[i] = min(next_dp[i], dp[j])
                k = bisect.bisect_right(arr2, j)
                if k < len(arr2):
                    next_dp[arr2[k]] = min(next_dp[arr2[k]], dp[j]+1)
            dp = next_dp
        if dp:
            return min(dp.itervalues())
        return -1
