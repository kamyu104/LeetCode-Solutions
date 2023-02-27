# Time:  O(m * n * log(m * n))
# Space: O(m * n)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minimumTime(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def dijkstra(start, target):
            best = [[float("inf")]*len(grid[0]) for _ in xrange(len(grid))]
            best[start[0]][start[1]] = 0
            min_heap = [(0, start[0], start[1])]
            while min_heap:
                curr, i, j = heapq.heappop(min_heap)
                if best[i][j] < curr:
                    continue
                if (i, j) == target:
                    break
                for di, dj in DIRECTIONS:  
                    ni, nj = i+di, j+dj   
                    if not (0 <= ni < len(grid) and 0 <= nj < len(grid[0]) and best[ni][nj] > max(grid[ni][nj]+int(grid[ni][nj]%2 == best[i][j]%2), curr+1)):
                        continue
                    best[ni][nj] = max(grid[ni][nj]+int(grid[ni][nj]%2 == best[i][j]%2), curr+1)
                    heapq.heappush(min_heap, (best[ni][nj], ni, nj))
            return best[target[0]][target[1]]

        if min(grid[0][1], grid[1][0]) > 1:
            return -1
        return dijkstra((0, 0), (len(grid)-1, len(grid[0])-1))
