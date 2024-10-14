# Time:  O(n^2)
# Space: O(n)

import collections


# dp
class Solution(object):
    def countWinningSequences(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9+7
        lookup = {x:i for i, x in enumerate("FWE")}
        dp = [collections.defaultdict(int) for _ in xrange(3)]
        for i, c in enumerate(s):
            new_dp = [collections.defaultdict(int) for _ in xrange(3)]
            x = lookup[c]
            for j in xrange(3):
                diff = (j-x+1)%3-1
                if i == 0:
                    new_dp[j][diff] = 1
                    continue
                for k in xrange(3):
                    if k == j:
                        continue
                    for v, c in dp[k].iteritems():
                        new_dp[j][v+diff] = (new_dp[j][v+diff]+c)%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (c for j in xrange(3) for v, c in dp[j].iteritems() if v >= 1), 0)
    
