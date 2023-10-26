# Time: O(n * nlogn + n^3 + n^2 * k) = O(n^3)
# Space: O(n * nlogn) = O(n^2 * logn)

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
        for i in xrange(1, len(divisors)):  # Time: O(nlogn), Space: O(nlogn)
            for j in xrange(i, len(divisors), i):
                divisors[j].append(i)
        dp = [[{} for _ in xrange(len(s))] for _ in xrange(len(s))]
        for l in xrange(1, len(s)+1):  # Time: O(n * nlogn + n^3), Space: O(n * nlogn)
            for left in xrange(len(s)-l+1):
                right = left+l-1
                for d in divisors[l]:
                    dp[left][right][d] = (dp[left+d][right-d][d] if left+d < right-d else 0)+sum(s[left+i] != s[(right-(d-1))+i] for i in xrange(d))
        dp2 = [[len(s)]*(k+1) for _ in xrange(len(s)+1)]
        dp2[0][0] = 0
        for i in xrange(len(s)):  # Time: O(n^2 * logn + n^2 * k), Space: O(n * k)
            for j in xrange(i):
                c = min(dp[j][i][d] for d in divisors[i-j+1] if d != i-j+1)
                for l in xrange(k):
                    dp2[i+1][l+1] = min(dp2[i+1][l+1], dp2[j][l]+c)
        return dp2[len(s)][k]


# Time:  O(n * nlogn  * n + n^2 * k) = O(n^3 * logn)
# Space: O(nlogn + n * k)
# number theory, dp
class Solution2(object):
    def minimumChanges(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def min_dist(left, right):
            return min(sum(s[left+i] != s[right-((i//d+1)*d-1)+(i%d)] for i in xrange((right-left+1)//2))
 for d in divisors[right-left+1])  # Time: O(nlogn)

        divisors = [[] for _ in xrange(len(s)+1)]
        for i in xrange(1, len(divisors)):  # Time: O(nlogn), Space: O(nlogn)
            for j in xrange(i+i, len(divisors), i):
                divisors[j].append(i)
        dp = [[len(s)]*(k+1) for _ in xrange(len(s)+1)]
        dp[0][0] = 0
        for i in xrange(len(s)):  # Time: O(n^2 * nlogn + n^2 * k), Space: O(n * k)
            for j in xrange(i):
                c = min_dist(j, i)
                for l in xrange(k):
                    dp[i+1][l+1] = min(dp[i+1][l+1], dp[j][l]+c)
        return dp[len(s)][k]
