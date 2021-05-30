# Time:  O(m * n * min(m, n))
# Space: O(m * n)

import heapq


class Solution(object):
    def getBiggestThree(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """	
        K = 3
        left = [[grid[i][j] for j in xrange(len(grid[i]))] for i in xrange(len(grid))]
        right = [[grid[i][j] for j in xrange(len(grid[i]))] for i in xrange(len(grid))]
        for i in xrange(1, len(grid)):
            for j in xrange(len(grid[0])-1):
                left[i][j] += left[i-1][j+1]
        for i in xrange(1, len(grid)):
            for j in xrange(1, len(grid[0])):
                right[i][j] += right[i-1][j-1]
        min_heap = []
        lookup = set()
        for k in xrange((min(len(grid), len(grid[0]))+1)//2):
            for i in xrange(k, len(grid)-k):
                for j in xrange(k, len(grid[0])-k):
                    total = (((left[i][j-k]-left[i-k][j])+(right[i][j+k]-right[i-k][j])+grid[i-k][j]) +  
                             ((left[i+k][j]-left[i][j+k])+(right[i+k][j]-right[i][j-k])-grid[i+k][j])) if k else grid[i][j]
                    if total in lookup:
                        continue
                    lookup.add(total)
                    heapq.heappush(min_heap, total)
                    if len(min_heap) == K+1:                        
                        lookup.remove(heapq.heappop(min_heap))
        min_heap.sort(reverse=True)
        return min_heap
