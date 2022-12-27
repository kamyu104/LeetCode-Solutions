# Time:  O((m * n + q) * log(m * n))
# Space: O(m * n)

import heapq


# bfs, heap, prefix sum, binary search
class Solution(object):
    def maxPoints(self, grid, queries):
        """
        :type grid: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        min_heap = [(grid[0][0], 0, 0)]
        lookup = [[False]*len(grid[0]) for _ in xrange(len(grid))]
        lookup[0][0] = True
        mx = 0
        cnt = collections.Counter()
        while min_heap:
            curr, i, j = heapq.heappop(min_heap)
            mx = max(mx, curr)
            cnt[mx] += 1
            for di, dj in directions:
                ni, nj = i+di, j+dj
                if not (0 <= ni < len(grid) and
                        0 <= nj < len(grid[0]) and
                        not lookup[ni][nj]):
                    continue
                lookup[ni][nj] = True
                heapq.heappush(min_heap, (grid[ni][nj], ni, nj))
        vals = sorted(cnt.iterkeys())
        prefix = [0]*(len(vals)+1)
        for i in xrange(len(vals)):
            prefix[i+1] += prefix[i]+cnt[vals[i]]
        return map(lambda x: prefix[bisect.bisect_left(vals, x)], queries)
