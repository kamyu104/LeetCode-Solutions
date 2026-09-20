# Time:  O(n^2)
# Space: O(1)

# array, inplace
class Solution(object):
    def cyclicShift(self, n, grid, rowShift, colShift):
        """
        :type n: int
        :type grid: List[List[int]]
        :type rowShift: List[int]
        :type colShift: List[int]
        :rtype: List[List[int]]
        """
        def rotate(i, j):
            x = grid[i][j]
            while x > 0:
                nj = (j-rowShift[i])%len(grid[0])
                ni = (i-colShift[nj])%len(grid)
                nx = grid[ni][nj]
                grid[ni][nj] = -x
                i, j, x = ni, nj, nx
    
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                rotate(i, j)
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                grid[i][j] = -grid[i][j]
        return grid
