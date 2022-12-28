# Time:  O(m * n)
# Space: O(n)

# dp
class Solution(object):
    def isThereAPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        if (len(grid)+len(grid[0])-1)%2:
            return False
        dp_left = [[float("inf")]*(len(grid[0])+1) for _ in xrange(2)]
        dp_left[0][1] = dp_left[1][0] = 0
        dp_right = [[float("-inf")]*(len(grid[0])+1) for _ in xrange(2)]
        dp_right[0][1] = dp_right[1][0] = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                dp_left[(i+1)%2][j+1] = min(dp_left[i%2][j+1], dp_left[(i+1)%2][j])+grid[i][j]
                dp_right[(i+1)%2][j+1] = max(dp_right[i%2][j+1], dp_right[(i+1)%2][j])+grid[i][j]
        return dp_left[len(grid)%2][-1] <= (len(grid)+len(grid[0])-1)//2 <= dp_right[len(grid)%2][-1]
