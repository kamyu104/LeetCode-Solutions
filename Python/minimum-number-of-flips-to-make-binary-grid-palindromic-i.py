# Time:  O(m * n)
# Space: O(1)

# array, greedy
class Solution(object):
    def minFlips(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def count(m, n, get):
            return sum(get(i, j) != get(i, ~j) for i in xrange(m) for j in xrange(n//2))

        m, n = len(grid), len(grid[0])
        return min(count(m, n, lambda i, j: grid[i][j]),
                   count(n, m, lambda i, j: grid[j][i]))
