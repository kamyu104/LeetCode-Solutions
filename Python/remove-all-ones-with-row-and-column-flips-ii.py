# Time:  O(m * n * 2^(m * n))
# Space: O(2^(m * n))

# dp, bitmasks
class Solution(object):
    def removeOnes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = [0]*len(grid)
        mask, bit = 0, 1
        for _ in xrange(len(grid[0])):
            mask += bit
            bit <<= 1
        for i in xrange(len(grid)):
            rows[i] = mask
            mask <<= len(grid[0])

        cols = [0]*len(grid[0])
        mask, bit = 0, 1
        for _ in xrange(len(grid)):
            mask += bit
            bit <<= len(grid[0])
        for j in xrange(len(grid[0])):
            cols[j] = mask
            mask <<= 1

        full_mask = (1<<(len(grid)*len(grid[0])))-1
        masks = [[full_mask for _ in xrange(len(grid[0]))] for _ in xrange(len(grid))]
        target, bit = 0, 1
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                target += bit*grid[i][j]
                masks[i][j] -= (rows[i]+cols[j]-bit)
                bit <<= 1

        dp = [float("inf") for _ in xrange(target+1)]
        dp[0] = 0
        for mask in xrange(1, target+1):
            for i in xrange(len(grid)):
                for j in xrange(len(grid[0])):
                    if grid[i][j]:
                        dp[mask] = min(dp[mask], dp[mask&masks[i][j]]+1)
        return dp[target]
