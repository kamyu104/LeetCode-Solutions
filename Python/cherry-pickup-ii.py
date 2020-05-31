# Time:  O(m * n^2)
# Space: O(n^2)

import itertools


class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [[[float("-inf")]*(len(grid[0])+2) for _ in xrange(len(grid[0])+2)] for _ in xrange(2)]
        dp[0][1][len(grid[0])] = grid[0][0] + grid[0][len(grid[0])-1]
        for i in xrange(1, len(grid)):
            for j in xrange(1, len(grid[0])+1):
                for k in xrange(1, len(grid[0])+1):
                    dp[i%2][j][k] = max(dp[(i-1)%2][j+d1][k+d2] for d1 in xrange(-1, 2) for d2 in xrange(-1, 2)) + \
                                    ((grid[i][j-1]+grid[i][k-1]) if j != k else grid[i][j-1])
        return max(itertools.imap(max, *dp[(len(grid)-1)%2]))


# Time:  O(m * n^2)
# Space: O(n^2)
import itertools


class Solution2(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [[[float("-inf")]*len(grid[0]) for _ in xrange(len(grid[0]))] for _ in xrange(2)]
        dp[0][0][len(grid[0])-1] = grid[0][0] + grid[0][len(grid[0])-1]
        for i in xrange(1, len(grid)):
            for j in xrange(len(grid[0])):
                for k in xrange(len(grid[0])):
                    dp[i%2][j][k] = max(dp[(i-1)%2][j+d1][k+d2] for d1 in xrange(-1, 2) for d2 in xrange(-1, 2)
                                        if 0 <= j+d1 < len(grid[0]) and 0 <= k+d2 < len(grid[0])) + \
                                    ((grid[i][j]+grid[i][k]) if j != k else grid[i][j])
        return max(itertools.imap(max, *dp[(len(grid)-1)%2]))
