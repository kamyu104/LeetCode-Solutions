# Time:  O(nlogn)
# Spade: O(n)

# sort, greedy
class Solution(object):
    def minRectanglesToCoverPoints(self, points, w):
        """
        :type points: List[List[int]]
        :type w: int
        :rtype: int
        """
        points.sort(key=lambda x: x[0])
        result = 0
        left = -(w+1)
        for right, _ in points:
            if right-left <= w:
                continue
            left = right
            result += 1
        return result
