# Time:  O(m * n * k)
# Space: O(m * n)

# dp
class Solution(object):
    def minCost(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        dp = [[INF]*len(grid[0]) for _ in xrange(len(grid))]
        dp[0][0] = grid[0][0]
        for _ in xrange(k+1):
            new_dp = [row[:] for row in dp]
            for i in xrange(len(grid)):
                mn = INF
                for j in xrange(len(grid[0])):
                    mn += grid[i][j]
                    mn = min(mn, dp[i][j])
                    new_dp[i][j] = min(new_dp[i][j], mn)
                mn = INF
                for j in reversed(xrange(len(grid[0]))):
                    mn += grid[i][j]
                    mn = min(mn, dp[i][j])
                    new_dp[i][j] = min(new_dp[i][j], mn)
            for j in xrange(len(grid[0])):
                mn = INF
                for i in xrange(len(grid)):
                    mn += grid[i][j]
                    mn = min(mn, dp[i][j])
                    new_dp[i][j] = min(new_dp[i][j], mn)
                mn = INF
                for i in reversed(xrange(len(grid))):
                    mn += grid[i][j]
                    mn = min(mn, dp[i][j])
                    new_dp[i][j] = min(new_dp[i][j], mn)
            dp = new_dp
        return dp[-1][-1] if dp[-1][-1] is not INF else -1


# Time:  O(m * n * k * log(m * n * k))
# Space: O(m * n * k)
import collections
import heapq


# dijkstra's algorithm
class Solution2(object):
    def minCost(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        start = (0, 0, -1, -1)
        dist = collections.defaultdict(lambda: INF)
        dist[start] = grid[0][0]
        min_heap = [(dist[start], 0, 0, -1, -1)]
        while min_heap:
            c, i, j, d, t = heapq.heappop(min_heap)
            if c != dist[i, j, d, t]:
                continue
            if i == len(grid)-1 and j == len(grid[0])-1:
                return c
            for nd, (di, dj) in enumerate(DIRECTIONS):
                ni, nj = i+di, j+dj
                if not (0 <= ni < len(grid) and 0 <= nj < len(grid[0])):
                    continue
                nt = t+(1 if d != nd else 0)
                if nt > k:
                    continue
                if c+grid[ni][nj] >= dist[ni, nj, nd, nt]:
                    continue
                dist[ni, nj, nd, nt] = c+grid[ni][nj]
                heapq.heappush(min_heap, (dist[ni, nj, nd, nt], ni, nj, nd, nt))
        return -1
