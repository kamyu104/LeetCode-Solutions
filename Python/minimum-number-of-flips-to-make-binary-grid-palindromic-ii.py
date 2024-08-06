# Time:  O(m * n)
# Space: O(1)

# array, greedy
class Solution(object):
    def minFlips(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        result = 0
        for i in xrange(m//2):
            for j in xrange(n//2):
                c = grid[i][j]+grid[i][~j]+grid[~i][j]+grid[~i][~j]
                result += min(c, 4-c)
        diff = cnt1 = 0
        if m%2:
            for j in xrange(n//2):
                diff += grid[m//2][j]^grid[m//2][~j]
                cnt1 += grid[m//2][j]+grid[m//2][~j]
        if n%2:
            for i in xrange(m//2):
                diff += grid[i][n//2]^grid[~i][n//2]
                cnt1 += grid[i][n//2]+grid[~i][n//2]
        if m%2 and n%2:
            result += grid[m//2][n//2]
        if diff == 0:
            result += (-cnt1)%4
        return result+diff
