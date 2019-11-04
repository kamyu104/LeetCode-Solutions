# Time:  O(n * l^2)
# Space: O(n * l)

import collections


class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words.sort(key=len)
        dp = collections.defaultdict(int)
        for w in words:
            for i in xrange(len(w)):
                dp[w] = max(dp[w], dp[w[:i]+w[i+1:]]+1)
        return max(dp.itervalues())
