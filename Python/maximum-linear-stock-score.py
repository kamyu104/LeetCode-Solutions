# Time:  O(n)
# Space: O(n)

import collections


# math, freq table
class Solution(object):
    def maxScore(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        cnt = collections.Counter()
        for i, x in enumerate(prices):
            cnt[x-i] += x
        return max(cnt.itervalues())
