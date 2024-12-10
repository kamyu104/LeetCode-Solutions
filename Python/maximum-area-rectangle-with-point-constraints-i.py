# Time:  O(nlogn)
# Space: O(n)

# sort, fenwick tree, hash table
class Solution(object):
    def maxRectangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        class BIT(object):  # 0-indexed.
            def __init__(self, n):
                self.__bit = [0]*(n+1)  # Extra one for dummy node.

            def add(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] += val
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = 0
                while i > 0:
                    ret += self.__bit[i]
                    i -= (i & -i)
                return ret
    
        points.sort()
        y_to_idx = {y:idx for idx, y in enumerate(sorted(set(y for _, y in points)))}
        bit = BIT(len(y_to_idx))
        lookup = {}
        result = -1
        for i, (x, y) in enumerate(points):
            y_idx = y_to_idx[y]
            bit.add(y_idx, +1)
            if not (i-1 >= 0 and points[i-1][0] == x):
                continue
            prev_y_idx = y_to_idx[points[i-1][1]]
            curr = bit.query(y_idx)-bit.query(prev_y_idx-1)
            if (prev_y_idx, y_idx) in lookup and lookup[prev_y_idx, y_idx][0] == curr-2:
                result = max(result, (x-lookup[prev_y_idx, y_idx][1])*(y-points[i-1][1]))
            lookup[prev_y_idx, y_idx] = (curr, x)
        return result


# Time:  O(n^2)
# Space: O(1)
# sort, brute force
class Solution2(object):
    def maxRectangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result = -1
        points.sort()
        for i in xrange(len(points)-3):
            if points[i][0] != points[i+1][0]:
                continue
            j = next((j for j in xrange(i+2, len(points)-1) if points[i][1] <= points[j][1] <= points[i+1][1]), len(points)-1)
            if j == len(points)-1 or not (points[j][0] == points[j+1][0] and points[i][1] == points[j][1] and points[i+1][1] == points[j+1][1]):
                continue
            result = max(result, (points[i+1][1]-points[i][1])*(points[j][0]-points[i][0]))
        return result
 
