# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def findBall(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        result = []
        for c in xrange(len(grid[0])):
            for r in xrange(len(grid)):
                nc = c+grid[r][c]
                if not (0 <= nc < len(grid[0]) and grid[r][nc] == grid[r][c]):
                    c = -1
                    break
                c = nc
            result.append(c)
        return result
