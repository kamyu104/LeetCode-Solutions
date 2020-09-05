# Time:  O(m * n * log(m + n)) ~ O(m * n * log(m * n))
# Space: O(m * n)

from heapq import heappush, heappop

class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        m = len(heightMap)
        if not m:
            return 0
        n = len(heightMap[0])
        if not n:
            return 0

        is_visited = [[False for i in xrange(n)] for j in xrange(m)]

        heap = []
        for i in xrange(m):
            heappush(heap, [heightMap[i][0], i, 0])
            is_visited[i][0] = True
            heappush(heap, [heightMap[i][n-1], i, n-1])
            is_visited[i][n-1] = True
        for j in xrange(1, n-1):
            heappush(heap, [heightMap[0][j], 0, j])
            is_visited[0][j] = True
            heappush(heap, [heightMap[m-1][j], m-1, j])
            is_visited[m-1][j] = True

        trap = 0
        while heap:
            height, i, j = heappop(heap)
            for (dx, dy) in [(1,0), (-1,0), (0,1), (0,-1)]:
                x, y = i+dx, j+dy
                if 0 <= x < m and 0 <= y < n and not is_visited[x][y]:
                    trap += max(0, height - heightMap[x][y])
                    heappush(heap, [max(height, heightMap[x][y]), x, y])
                    is_visited[x][y] = True

        return trap

