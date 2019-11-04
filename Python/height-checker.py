# Time:  O(nlogn)
# Space: O(n)

import itertools


class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        return sum(i != j for i, j in itertools.izip(heights, sorted(heights)))
