# Time:  O(m * n)
# Space: O(m * n)

class Solution(object):
    def possibleToStamp(self, grid, stampHeight, stampWidth):
        """
        :type grid: List[List[int]]
        :type stampHeight: int
        :type stampWidth: int
        :rtype: bool
        """
        prefix = [[0]*(len(grid[0])+1) for _ in xrange(len(grid)+1)]
        fit = [[0]*len(grid[0]) for _ in xrange(len(grid))]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                prefix[i+1][j+1] = prefix[i+1][j]+prefix[i][j+1]-prefix[i][j]+(1^grid[i][j])
                if i+1 >= stampHeight and j+1 >= stampWidth:
                    x, y = i+1-stampHeight, j+1-stampWidth
                    fit[i][j] = int(prefix[i+1][j+1]-prefix[x][j+1]-prefix[i+1][y]+prefix[x][y] == stampWidth*stampHeight)
        prefix2 = [[0]*(len(grid[0])+1) for _ in xrange(len(grid)+1)]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                prefix2[i+1][j+1] = prefix2[i+1][j]+prefix2[i][j+1]-prefix2[i][j]+fit[i][j]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                x, y = min(i+stampHeight, len(grid)), min(j+stampWidth, len(grid[0]))
                if not grid[i][j] and not prefix2[x][y]-prefix2[i][y]-prefix2[x][j]+prefix2[i][j]:
                    return False
        return True
