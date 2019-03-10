# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def minDominoRotations(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        intersect = reduce(set.__and__, [set(d) for d in itertools.izip(A, B)])
        if not intersect:
            return -1
        x = intersect.pop()
        return min(len(A)-A.count(x), len(B)-B.count(x))
