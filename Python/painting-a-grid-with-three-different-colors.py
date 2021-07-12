# Time:  (m * n grids) * (O(3*3*2^(m-2)) possible states per grid) = O(n * m * 2^m)
# Space: O(3*3*2^(m-2)) = O(2^m)

import collections


class Solution(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        if m > n:
            m, n = n, m
        dp = collections.Counter({3**m-1: 1})
        basis = 3**(m-1)
        for idx in xrange(m*n):
            assert(len(dp) <= 3**2 * 2**(m-2))
            r, c = divmod(idx, m)
            new_dp = collections.Counter()
            for mask in dp:
                choices = {0, 1, 2}
                if r > 0:
                    choices.discard(mask%3)  # get up grid
                if c > 0:
                    choices.discard(mask//basis)  # get left grid
                for val in choices:
                    new_mask = (val*basis)+(mask//3)  # encoding mask
                    new_dp[new_mask] = (new_dp[new_mask]+dp[mask])%MOD 
            dp = new_dp
        return reduce(lambda x,y: (x+y)%MOD, dp.itervalues(), 0)
