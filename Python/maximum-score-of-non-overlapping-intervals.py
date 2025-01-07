# Time:  O(nlogn + n * k^2)
# Space: O(n * k^2)

import bisect


# dp, binary search
class Solution(object):
    def maximumWeight(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        K = 4
        lookup = {}
        for i, (l, r, w) in enumerate(intervals):
            if (r, l, w) not in lookup:
                lookup[r, l, w] = i
        sorted_intervals = sorted(lookup.iterkeys(), key=lambda x: x[0])
        dp = [[[0, []] for _ in xrange(K+1)] for _ in xrange(len(sorted_intervals)+1)]
        for i in xrange(len(dp)-1):
            j = bisect.bisect_right(sorted_intervals, (sorted_intervals[i][1], 0, 0))-1
            idx = lookup[sorted_intervals[i]]
            for k in xrange(1, len(dp[i])):
                new_dp = [dp[j+1][k-1][0]-sorted_intervals[i][2], dp[j+1][k-1][1][:]]
                insort(new_dp[1], idx)
                dp[i+1][k] = min(dp[i][k], new_dp)
        return dp[len(sorted_intervals)][K][1]


# Time:  O(nlogn + n * k^2)
# Space: O(n * k^2)
import bisect


# dp, binary search
class Solution2(object):
    def maximumWeight(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        K = 4
        lookup = {}
        for i, (l, r, w) in enumerate(intervals):
            if (l, r, w) not in lookup:
                lookup[l, r, w] = i
        sorted_intervals = sorted(lookup.iterkeys(), key=lambda x: x[0])
        dp = [[[0, []] for _ in xrange(K+1)] for _ in xrange(len(sorted_intervals)+1)]
        for i in reversed(xrange(len(dp)-1)):
            j = bisect.bisect_right(sorted_intervals, (sorted_intervals[i][1]+1, 0, 0))
            idx = lookup[sorted_intervals[i]]
            for k in xrange(1, len(dp[i])):
                new_dp = [dp[j][k-1][0]-sorted_intervals[i][2], dp[j][k-1][1][:]]
                insort(new_dp[1], idx)
                dp[i][k] = min(dp[i+1][k], new_dp)
        return dp[0][K][1]
