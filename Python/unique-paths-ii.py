# Time:  O(m * n)
# Space: O(m + n)

class Solution(object):
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m, n = len(obstacleGrid), len(obstacleGrid[0])

        ways = [0]*n
        ways[0] = 1
        for i in xrange(m):
            if obstacleGrid[i][0] == 1:
                ways[0] = 0
            for j in xrange(n):
                if obstacleGrid[i][j] == 1:
                    ways[j] = 0
                elif j>0:
                    ways[j] += ways[j-1]
        return ways[-1]

