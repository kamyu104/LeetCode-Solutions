# Time:  O(m * n * logk + nCr((k-1)*(2*k-1)+1), 3) * k) = O(m * n)
# Space: O(k * (m + n)) = O(m + n)

import heapq
import itertools


# heap, brute force
class Solution(object):
    def maximumValueSum(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        k = 3
        min_heaps = [[] for _ in xrange(len(board[0]))]
        for i in xrange(len(board)):
            min_heap = []
            for j in xrange(len(board[0])):
                heapq.heappush(min_heap, (board[i][j], i, j))
                if len(min_heap) == k+1:
                    heapq.heappop(min_heap)
            for v, i, j in min_heap:
                heapq.heappush(min_heaps[j], (v, i, j))
                if len(min_heaps[j]) == k+1:
                    heapq.heappop(min_heaps[j])
        min_heap = []
        for h in min_heaps:
            for x in h:
                heapq.heappush(min_heap, x)
                if len(min_heap) == ((k-1)*(2*k-1)+1)+1:  # each choice excludes at most 2k-1 candidates, we should have at least (k-1)*(2k-1)+1 candidates
                    heapq.heappop(min_heap)
        return max(x[0]+y[0]+z[0] for x, y, z in itertools.combinations(min_heap, k) if all(len({x[i], y[i], z[i]}) == k for i in xrange(1, 2+1)))
