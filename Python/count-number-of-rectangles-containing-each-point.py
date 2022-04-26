# Time:  O(nlogn + m * max_y * logn), n = len(rectangles), m = len(points)
# Space: O(n)

import bisect


# bucket sort, binary search
class Solution(object):
    def countRectangles(self, rectangles, points):
        """
        :type rectangles: List[List[int]]
        :type points: List[List[int]]
        :rtype: List[int]
        """
        max_y = max(y for _, y in rectangles)
        buckets = [[] for _ in xrange(max_y+1)]
        for x, y in rectangles:
            buckets[y].append(x)
        for bucket in buckets:
            bucket.sort()
        return [sum(len(buckets[y])-bisect.bisect_left(buckets[y], x) for y in xrange(y, max_y+1))
                for x, y in points]
