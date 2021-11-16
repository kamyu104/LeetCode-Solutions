# Time:  O(nlogn + qlogn)
# Space: O(1)

import bisect


class Solution(object):
    def maximumBeauty(self, items, queries):
        """
        :type items: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        items.sort()
        for i in xrange(len(items)-1):
            items[i+1][1] = max(items[i+1][1], items[i][1])
        result = []
        for q in queries:
            i = bisect.bisect_left(items, [q+1])
            result.append(items[i-1][1] if i else 0)
        return result
