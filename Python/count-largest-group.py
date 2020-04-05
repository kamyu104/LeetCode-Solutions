# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def countLargestGroup(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = collections.Counter()
        for x in xrange(1, n+1):
            count[sum(map(int, str(x)))] += 1
        max_count = max(count.itervalues())
        return sum(v == max_count for v in count.itervalues())
