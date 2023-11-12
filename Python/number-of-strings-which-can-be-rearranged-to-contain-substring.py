# Time:  O(logn)
# Space: O(1)

# combinatorics, principle of inclusion-exclusion
class Solution(object):
    def stringCount(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        return (pow(26, n, MOD)-
                (25+25+25+n)*pow(25, n-1, MOD)+      # no l, t, e, ee
                (24+24+24+n+n+0)*pow(24, n-1, MOD)-  # no l|t, l|e, t|e, l|ee, t|ee, e|ee
                (23+n+0+0)*pow(23, n-1, MOD))%MOD    # no l|t|e, l|t|ee, l|e|ee, t|e|ee


# Time:  O(2^4 * n) = O(n)
# Space: O(2^4) = O(1)
# bitmasks, dp
class Solution2(object):
    def stringCount(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        L, E, EE, T = [1<<i for i in xrange(4)]
        dp = [0]*(1<<4)
        dp[0] = 1
        for _ in xrange(n):
            new_dp = [0]*(1<<4)
            for mask in xrange(len(dp)):
                new_dp[mask|L] = (new_dp[mask|L]+dp[mask])%MOD
                if not (mask & E):
                    new_dp[mask|E] = (new_dp[mask|E]+dp[mask])%MOD
                else:
                    new_dp[mask|EE] = (new_dp[mask|EE]+dp[mask])%MOD
                new_dp[mask|T] = (new_dp[mask|T]+dp[mask])%MOD
                new_dp[mask] = (new_dp[mask]+23*dp[mask])%MOD
            dp = new_dp
        return dp[-1]
