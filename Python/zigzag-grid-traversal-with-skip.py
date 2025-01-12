# Time:  O(n * m)
# Space: O(1)

# array
class Solution(object):
    def zigzagTraversal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        result = []
        for i in xrange(len(grid)):
            if i%2 == 0:
                result.extend(grid[i][j] for j in xrange(0, len(grid[0]), 2))
            else:
                result.extend(grid[i][j] for j in reversed(xrange(1, len(grid[0]), 2)))
        return result
