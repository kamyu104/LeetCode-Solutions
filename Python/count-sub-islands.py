# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def countSubIslands(self, grid1, grid2):
        """
        :type grid1: List[List[int]]
        :type grid2: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def dfs(grid1, grid2, i, j):
            if not (0 <= i < len(grid2) and
                    0 <= j < len(grid2[0]) and
                    grid2[i][j] == 1):
                return 1
            grid2[i][j] = 0
            result = grid1[i][j]
            for di, dj in directions:
                result &= dfs(grid1, grid2, i+di, j+dj)
            return result
            
        return sum(dfs(grid1, grid2, i, j) for i in xrange(len(grid2)) for j in xrange(len(grid2[0])) if grid2[i][j])
