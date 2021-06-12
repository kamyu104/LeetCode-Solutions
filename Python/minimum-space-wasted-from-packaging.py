# Time:  O(mlogm + nlogn + mlogn)
# Space: O(1)

import bisect


class Solution(object):
    def minWastedSpace(self, packages, boxes):
        """
        :type packages: List[int]
        :type boxes: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        INF = float("inf")

        packages.sort()
        result = INF
        for box in boxes:
            box.sort()
            if box[-1] < packages[-1]:
                continue
            curr = left = 0
            for b in box:
                right = bisect.bisect_right(packages, b, left)
                curr += b * (right-left)
                left = right
            result = min(result, curr)
        return (result-sum(packages))%MOD if result != INF else -1
