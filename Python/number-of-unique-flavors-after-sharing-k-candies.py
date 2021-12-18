# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def shareCandies(self, candies, k):
        """
        :type candies: List[int]
        :type k: int
        :rtype: int
        """
        cnt = collections.Counter(candies[i] for i in xrange(k, len(candies)))
        result = curr = len(cnt)
        for i in xrange(k, len(candies)):
            cnt[candies[i]] -= 1
            curr += (cnt[candies[i-k]] == 0) - (cnt[candies[i]] == 0)
            cnt[candies[i-k]] += 1
            result = max(result, curr)
        return result
