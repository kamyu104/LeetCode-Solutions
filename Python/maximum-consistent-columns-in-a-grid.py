# Time:  O(m * nlogn + m * n^2 / 64 + n^3 / 64 + n^2) = O(max(m, n) * n^2 / 64)
# Space: O(n^2 / 64)

import bisect


# sort, prefix sum, binary search, dp, bitmasks
class Solution(object):
    def maxConsistentColumns(self, grid, limit):
        lookup = [(1<<len(grid[0]))-1]*len(grid[0])
        for i in xrange(len(grid)):
            idxs = sorted(xrange(len(grid[0])), key=lambda j: grid[i][j])
            arr = [grid[i][j] for j in idxs]
            prefix = [0]*(len(grid[0])+1) 
            for j in xrange(len(grid[0])):
                prefix[j+1] = prefix[j]|(1<<idxs[j])
            for j in xrange(len(grid[0])):
                lookup[j] &= prefix[bisect.bisect_right(arr, grid[i][j]+limit)]^prefix[bisect.bisect_left(arr, grid[i][j]-limit)]
        dp = [1]*len(grid[0])
        for j in xrange(len(grid[0])):
            mx = 0
            mask = lookup[j]&((1<<j)-1)
            while mask:
                k = (mask&-mask).bit_length()-1
                mx = max(mx, dp[k])
                mask ^= (mask&-mask)
            dp[j] = mx+1
        return max(dp)


# Time:  O(m * n^2)
# Space: O(n)
# dp
class Solution2(object):
    def maxConsistentColumns(self, grid, limit):
        """
        :type grid: List[List[int]]
        :type limit: int
        :rtype: int
        """
        dp = [1]*len(grid[0])
        for i in xrange(len(grid[0])):
            for j in xrange(i):
                if dp[j]+1 <= dp[i]:
                    continue
                if all(abs(row[i]-row[j]) <= limit for row in grid):
                    dp[i] = dp[j]+1
        return max(dp)
