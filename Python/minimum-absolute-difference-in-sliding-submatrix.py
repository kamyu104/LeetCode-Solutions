# Time:  O(m * n * k^2 * logk)
# Space: O(k^2)

# brute force, sort
class Solution(object):
    def minAbsDiff(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        result = [[-1]*(len(grid[0])-(k-1)) for _ in xrange(len(grid)-(k-1))]
        for i in xrange(len(grid)-(k-1)):
            for j in xrange(len(grid[0])-(k-1)):
                vals = sorted({grid[i+di][j+dj] for di in xrange(k) for dj in xrange(k)})
                result[i][j] = min(vals[x+1]-vals[x] for x in xrange(len(vals)-1)) if len(vals) != 1 else 0
        return result
