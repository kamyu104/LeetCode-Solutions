# Time:  O(n * r^2 * logr)
# Space: O(r^2)

import collections


# dp, number theory
class Solution(object):
    def subsequencePairCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        dp = collections.defaultdict(int)
        dp[(0, 0)] = 1
        for x in nums:
            new_dp = collections.defaultdict(int)
            for (g1, g2), cnt in dp.items():
                ng1, ng2 = gcd(g1, x), gcd(g2, x)
                new_dp[(g1, g2)] = (new_dp[(g1, g2)]+cnt)%MOD
                new_dp[(ng1, g2)] = (new_dp[(ng1, g2)]+cnt)%MOD
                new_dp[(g1, ng2)] = (new_dp[(g1, ng2)]+cnt)%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (cnt for (g1, g2), cnt in dp.iteritems() if g1 == g2 > 0), 0)


# Time:  O(n * r^2 * logr)
# Space: O(r^2)
import collections


# dp, number theory
class SolutionTLE(object):
    def subsequencePairCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        mx = max(nums)
        dp = [[0]*(mx+1) for _ in xrange(mx+1)]
        dp[0][0] = 1
        for x in nums:
            new_dp = [row[:] for row in dp]
            for g1 in reversed(xrange(mx+1)):
                for g2 in reversed(xrange(mx+1)):
                    ng1, ng2 = gcd(g1, x), gcd(g2, x)
                    new_dp[ng1][g2] = (new_dp[ng1][g2]+dp[g1][g2])%MOD
                    new_dp[g1][ng2] = (new_dp[g1][ng2]+dp[g1][g2])%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (dp[g][g] for g in xrange(1, mx+1)), 0)
