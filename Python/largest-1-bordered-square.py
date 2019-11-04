# Time:  O(n^3)
# Space: O(n^2)

class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        top, left = [a[:] for a in grid], [a[:] for a in grid]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if not grid[i][j]:
                    continue
                if i:
                    top[i][j] = top[i-1][j] + 1
                if j:
                    left[i][j] = left[i][j-1] + 1
        for l in reversed(xrange(1, min(len(grid), len(grid[0]))+1)):
            for i in xrange(len(grid)-l+1):
                for j in xrange(len(grid[0])-l+1):
                    if min(top[i+l-1][j],
                           top[i+l-1][j+l-1],
                           left[i][j+l-1],
                           left[i+l-1][j+l-1]) >= l:
                        return l*l
        return 0
