# Time:  O(k^3 * n^2)
# Space: O(k^2 * n)

import collections


class Solution(object):
    def getProbability(self, balls):
        """
        :type balls: List[int]
        :rtype: float
        """
        def nCrs(n):  # Time: O(n), Space: O(n)
            cs = []
            c = 1
            cs.append(c)
            for k in xrange(1, n+1):
                c *= n-k+1
                c //= k
                cs.append(c)
            return cs
        
        dp = collections.defaultdict(int)
        dp[0, 0] = 1  # dp[i, j] is the number of ways with number difference i and color difference j
        for n in balls:  # O(k) times
            new_dp = collections.defaultdict(int)
            for (ndiff, cdiff), count in dp.iteritems():  # O(k^2 * n) times
                for k, new_count in enumerate(nCrs(n)):  # O(n) times
                    new_ndiff = ndiff+(k-(n-k))
                    new_cdiff = cdiff-1 if k == 0 else (cdiff+1 if k == n else cdiff)
                    new_dp[new_ndiff, new_cdiff] += count*new_count
            dp = new_dp
        total = sum(balls)
        return float(dp[0, 0])/nCrs(total)[total//2]
