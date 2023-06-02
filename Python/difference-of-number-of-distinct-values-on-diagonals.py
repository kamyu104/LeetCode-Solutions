# Time:  O(m * n)
# Space: O(min(m, n))

# prefix sum
class Solution(object):
    def differenceOfDistinctValues(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        def update(i, j):
            lookup = set()
            for k in xrange(min(len(grid)-i, len(grid[0])-j)):
                result[i+k][j+k] = len(lookup)
                lookup.add(grid[i+k][j+k])
            lookup.clear()
            for k in reversed(xrange(min(len(grid)-i, len(grid[0])-j))):
                result[i+k][j+k] = abs(result[i+k][j+k]-len(lookup))
                lookup.add(grid[i+k][j+k])

        result = [[0]*len(grid[0]) for _ in xrange(len(grid))]
        for j in xrange(len(grid[0])):
            update(0, j)
        for i in xrange(1, len(grid)):
            update(i, 0)
        return result
