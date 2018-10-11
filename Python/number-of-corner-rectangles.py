# Time:  O(n * m^2), n is the number of rows with 1s, m is the number of cols with 1s
# Space: O(n * m)

class Solution(object):
    def countCornerRectangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = [[c for c, val in enumerate(row) if val]
                for row in grid]
        result = 0
        for i in xrange(len(rows)):
            lookup = set(rows[i])
            for j in xrange(i):
                count = sum(1 for c in rows[j] if c in lookup)
                result += count*(count-1)/2
        return result

