# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def fill(grid, i, j):
            if not (0 <= i < len(grid) and 
                    0 <= j < len(grid[0]) and 
                    grid[i][j] == 0):
                return False
            grid[i][j] = 1
            for dx, dy in directions:
                fill(grid, i+dx, j+dy)
            return True

        for j in xrange(len(grid[0])):
            fill(grid, 0, j)
            fill(grid, len(grid)-1, j)
        for i in xrange(1, len(grid)):
            fill(grid, i, 0)
            fill(grid, i, len(grid[0])-1)
        result = 0
        for i in xrange(1, len(grid)-1):
            for j in xrange(1, len(grid[0])-1):
                if fill(grid, i, j):
                    result += 1
        return result
