# Time:  O(n + d * r), d = len(set(nums))
# Space: O(d + r)

import collections


# freq table, knapsack dp, sliding window, combinatorics
class Solution(object):
    def countSubMultisets(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: int
        :type r: int
        :rtype: int
        """
        MOD = 10**9+7
        cnt = collections.Counter(nums)
        dp = [0]*(r+1)
        dp[0] = 1
        for x, c in cnt.iteritems():
            for i in reversed(xrange(max(r-x+1, 1), r+1)):
                curr = reduce(lambda x, y: (x+y)%MOD, (dp[i-x*j] for j in xrange(min(c, i//x+1))))
                for j in reversed(xrange((i-1)%x+1, i+1, x)):
                    curr = (curr+(dp[j-x*c] if j-x*c >= 0 else 0)-dp[j])%MOD
                    dp[j] = (dp[j]+curr)%MOD
        return (reduce(lambda x, y: (x+y)%MOD, (dp[i] for i in range(l, r+1)))*(cnt[0]+1))%MOD
