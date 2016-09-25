# Time:  O(m * n * log(m + n)) ~ O(m * n * log(m * n))
# Space: O(m * n)

# Given an m x n matrix of positive integers representing the height of each unit cell in
# a 2D elevation map, compute the volume of water it is able to trap after raining.
#
# Note:
# Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
#
# Example:
#
# Given the following 3x6 height map:
# [
#   [1,4,3,1,3,2],
#   [3,2,1,3,2,4],
#   [2,3,3,2,3,1]
# ]
#
# Return 4.

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

        visited = [[False for i in xrange(n)] for j in xrange(m)]
        
        heap = []
        for i in xrange(m):
            heappush(heap, [heightMap[i][0], i, 0])
            visited[i][0] = True
            heappush(heap, [heightMap[i][n-1], i, n-1])
            visited[i][n-1] = True
        for j in xrange(n):
            heappush(heap, [heightMap[0][j], 0, j])
            visited[0][j] = True
            heappush(heap, [heightMap[m-1][j], m-1, j])
            visited[m-1][j] = True

        trap = 0
        while heap:
            height, i, j = heappop(heap)
            for (dx, dy) in [(1,0), (-1,0), (0,1), (0,-1)]:
                x, y = i+dx, j+dy
                if 0 <= x < m and 0 <= y < n and not visited[x][y]:
                    trap += max(0, height - heightMap[x][y])
                    heappush(heap, [max(height, heightMap[x][y]), x, y])
                    visited[x][y] = True

        return trap
