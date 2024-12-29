# Time:  O(m * n)
# Space: O(1)

# greedy
class Solution(object):
    def minimumOperations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        result = 0
        for i in xrange(len(grid)-1):
            for j in xrange(len(grid[0])):
                diff = max((grid[i][j]+1)-grid[i+1][j], 0)
                grid[i+1][j] += diff
                result += diff
        return result
