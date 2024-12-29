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
                if grid[i][j]+1 <= grid[i+1][j]:
                    continue
                result += (grid[i][j]+1)-grid[i+1][j]
                grid[i+1][j] = grid[i][j]+1
        return result
