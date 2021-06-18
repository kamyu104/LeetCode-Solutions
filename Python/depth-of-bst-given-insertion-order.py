# Time:  O(nlogn)
# Space: O(n)

import sortedcontainers


class Solution(object):
    def maxDepthBST(self, order):
        """
        :type order: List[int]
        :rtype: int
        """
        depths = sortedcontainers.SortedDict({float("-inf"):0, float("inf"):0})
        values_view = depths.values()
        result = 0
        for x in order:
            i = depths.bisect_right(x)
            depths[x] = max(values_view[i-1:i+1])+1
            result = max(result, depths[x])
        return result
