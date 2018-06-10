# Time:  O(nlogn)
# Space: O(n)

# We are given a list of (axis-aligned) rectangles.
# Each rectangle[i] = [x1, y1, x2, y2] ,
# where (x1, y1) are the coordinates of the bottom-left corner,
# and (x2, y2) are the coordinates of the top-right corner of
# the ith rectangle.
#
# Find the total area covered by all rectangles in the plane.
# Since the answer may be too large, return it modulo 10^9 + 7.
#
# Example 1:
#
# Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
# Output: 6
# Explanation: As illustrated in the picture.
# Example 2:
#
# Input: [[0,0,1000000000,1000000000]]
# Output: 49
# Explanation: The answer is 10^18 modulo (10^9 + 7),
# which is (10^9)^2 = (-7)^2 = 49.
#
# Note:
# - 1 <= rectangles.length <= 200
# - rectanges[i].length = 4
# - 0 <= rectangles[i][j] <= 10^9
# - The total area covered by all rectangles will never exceed 2^63 - 1 and
#   thus will fit in a 64-bit signed integer.


class SegmentTreeNode(object):
    def __init__(self, start, end):
        self.start, self.end = start, end
        self.total = self.count = 0
        self._left = self._right = None

    def mid(self):
        return (self.start+self.end) // 2

    def left(self):
        self._left = self._left or SegmentTreeNode(self.start, self.mid())
        return self._left

    def right(self):
        self._right = self._right or SegmentTreeNode(self.mid(), self.end)
        return self._right

    def update(self, X, i, j, val):
        if i >= j:
            return 0
        if self.start == i and self.end == j:
            self.count += val
        else:
            self.left().update(X, i, min(self.mid(), j), val)
            self.right().update(X, max(self.mid(), i), j, val)
        if self.count > 0:
            self.total = X[self.end]-X[self.start]
        else:
            self.total = self.left().total + self.right().total
        return self.total


class Solution(object):
    def rectangleArea(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        OPEN, CLOSE = 1, -1
        events = []
        X = set()
        for x1, y1, x2, y2 in rectangles:
            events.append((y1, OPEN, x1, x2))
            events.append((y2, CLOSE, x1, x2))
            X.add(x1)
            X.add(x2)
        events.sort()
        X = sorted(X)
        Xi = {x: i for i, x in enumerate(X)}

        st = SegmentTreeNode(0, len(X)-1)
        result = 0
        cur_x_sum = 0
        cur_y = events[0][0]
        for y, typ, x1, x2 in events:
            result += cur_x_sum * (y-cur_y)
            cur_x_sum = st.update(X, Xi[x1], Xi[x2], typ)
            cur_y = y
        return result % (10**9+7)
