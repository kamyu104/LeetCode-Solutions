# Time:  O(q * n)
# Space: O(1)

class Solution(object):
    def countPoints(self, points, queries):
        """
        :type points: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        result = []
        for i, j, r in queries:
            result.append(0)
            for x, y in points:
                if (x-i)**2+(y-j)**2 <= r**2:
                    result[-1] += 1
        return result
