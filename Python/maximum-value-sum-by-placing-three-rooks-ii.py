# Time:  O(m * n * logk + nCr((k-1)*(2*k-1)+1), k) * k) = O(m * n)
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
        return max(sum(x[0] for x in c) for c in itertools.combinations(min_heap, k) if len({x[1] for x in c}) == k == len({x[2] for x in c}))


# Time:  O(m * n * logk + nCr((k-1)*(2*k-1)+1), k) * k) = O(m * n)
# Space: O(k * (m + n)) = O(m + n)
import heapq
import itertools


# heap, brute force
class Solution2(object):
    def maximumValueSum(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        k = 3
        rows = [heapq.nlargest(k, [(board[i][j], i, j) for j in xrange(len(board[0]))]) for i in xrange(len(board))]
        cols = [heapq.nlargest(k, [(board[i][j], i, j) for i in xrange(len(board))]) for j in xrange(len(board[0]))]
        min_heap = heapq.nlargest((k-1)*(2*k-1)+1, set(itertools.chain(*rows)) & set(itertools.chain(*cols)))  # each choice excludes at most 2k-1 candidates, we should have at least (k-1)*(2k-1)+1 candidates
        return max(sum(x[0] for x in c) for c in itertools.combinations(min_heap, k) if len({x[1] for x in c}) == k == len({x[2] for x in c}))
