# Time:  O(n)
# Space: O(n)

import itertools


class Solution(object):
    def flipgame(self, fronts, backs):
        """
        :type fronts: List[int]
        :type backs: List[int]
        :rtype: int
        """
        same = {n for i, n in enumerate(fronts) if n == backs[i]}
        result = float("inf")
        for n in itertools.chain(fronts, backs):
            if n not in same:
                result = min(result, n)
        return result if result < float("inf") else 0

