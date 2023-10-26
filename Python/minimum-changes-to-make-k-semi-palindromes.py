# Time:  O(n * nlogn * n + n^2 * k) = O(n^3 * logn + n^2 * k)
# Space: O(n * nlogn + n * k) = O(n^2 * logn + n * k)

import collections


# number theory, dp
class Solution(object):
    def minimumChanges(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        divisors = [[] for _ in xrange(len(s)+1)]
        for i in xrange(1, len(divisors)):
            for j in xrange(i, len(divisors), i):
                divisors[j].append(i)
        dp = [[{} for _ in xrange(len(s))] for _ in xrange(len(s))]
        for l in xrange(1, len(s)+1):
            for left in xrange(len(s)-l+1):
                right = left+l-1
                for d in divisors[l]:
                    dp[left][right][d] = (dp[left+d][right-d][d] if left+d < right-d else 0)+sum(s[left+i] != s[(right-(d-1))+i] for i in xrange(d))
        dp2 = [[len(s)]*(k+1) for _ in xrange(len(s)+1)]
        dp2[0][0] = 0
        for i in xrange(len(s)):
            for j in xrange(i):
                c = min(dp[j][i][d] for d in divisors[i-j+1] if d != i-j+1)
                for l in xrange(k):
                    dp2[i+1][l+1] = min(dp2[i+1][l+1], dp2[j][l]+c)
        return dp2[len(s)][k]
