# Time:  O(nlogn)
# Space: O(n)

import itertools


class Solution(object):
    def maxWidthOfVerticalArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        sorted_x = sorted({x for x, y in points})
        return max([b-a for a, b in itertools.izip(sorted_x, sorted_x[1:])] + [0])
