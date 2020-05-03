# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def destCity(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: str
        """
        A, B = map(set, itertools.izip(*paths))
        return (B-A).pop()
