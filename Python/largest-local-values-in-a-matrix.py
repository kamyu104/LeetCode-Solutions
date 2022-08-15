# Time:  O(m * n)
# Space: O(1)

# array
class Solution(object):
    def largestLocal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        def find_max(i, j):
            return max(grid[ni][nj] for ni in xrange(i, i+3) for nj in xrange(j, j+3))

        return [[find_max(i, j) for j in xrange(len(grid[0])-2)] for i in xrange(len(grid)-2)]
