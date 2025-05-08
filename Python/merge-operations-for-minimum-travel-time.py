# Time:  O((n - k) * k^3)
# Space: O(k^2)

import collections


# prefix sum, dp
class Solution(object):
    def minTravelTime(self, l, n, k, position, time):
        """
        :type l: int
        :type n: int
        :type k: int
        :type position: List[int]
        :type time: List[int]
        :rtype: int
        """
        prefix = [0]*(n+1)
        for i in xrange(n):
            prefix[i+1] = prefix[i]+time[i]
        dp = collections.defaultdict(lambda: collections.defaultdict(lambda: float("inf")))
        dp[0][time[0]] = 0
        for cnt in xrange(2, (n-k)+1):
            new_dp = collections.defaultdict(lambda: collections.defaultdict(lambda: float("inf")))
            for i in xrange(cnt-1, (cnt-1)+(k+1)):
                for j in xrange(cnt-2, i):
                    for t, c in dp[j].iteritems():
                        new_dp[i][prefix[i+1]-prefix[j+1]] = min(new_dp[i][prefix[i+1]-prefix[j+1]], (position[i]-position[j])*t+c)
            dp = new_dp
        return min(dp[n-1].itervalues())
