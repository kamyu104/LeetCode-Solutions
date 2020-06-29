# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findMaxValueOfEquation(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: int
        """
        result = float("-inf")
        dq = collections.deque()
        for i, (x, y) in enumerate(points):
            while dq and points[dq[0]][0] < x-k:
                dq.popleft()
            if dq:
                result = max(result, (points[dq[0]][1]-points[dq[0]][0])+y+x)
            while dq and points[dq[-1]][1]-points[dq[-1]][0] <= y-x:
                dq.pop()
            dq.append(i)
        return result
