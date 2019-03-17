# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """
        result = 0
        count = collections.Counter()
        for t in time:
            result += count[-t%60]
            count[t%60] += 1
        return result
