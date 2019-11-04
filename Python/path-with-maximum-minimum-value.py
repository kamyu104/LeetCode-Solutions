# Time:  O(m * n * log(m * n))
# Space: O(m * n)

# binary search + dfs solution
class Solution(object):
    def maximumMinimumPath(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        def check(A, val, r, c, lookup):
            if r == len(A)-1 and c == len(A[0])-1:
                return True
            lookup.add((r, c))
            for d in directions:
                nr, nc = r + d[0], c + d[1]
                if 0 <= nr < len(A) and \
                   0 <= nc < len(A[0]) and \
                   (nr, nc) not in lookup and \
                   A[nr][nc] >= val and \
                   check(A, val, nr, nc, lookup):
                    return True
            return False
        
        vals, ceil = [], min(A[0][0], A[-1][-1])
        for i in xrange(len(A)):
            for j in xrange(len(A[0])):
                if A[i][j] <= ceil:
                    vals.append(A[i][j])
        vals = list(set(vals))
        vals.sort()
        left, right = 0, len(vals)-1
        while left <= right:
            mid = left + (right-left)//2
            if not check(A, vals[mid], 0, 0, set()):
                right = mid-1
            else:
                left = mid+1
        return vals[right]


# Time:  O(m * n * log(m * n))
# Space: O(m * n)
import heapq


# Dijkstra algorithm solution
class Solution2(object):
    def maximumMinimumPath(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        max_heap = [(-A[0][0], 0, 0)]
        lookup = set([(0, 0)])
        while max_heap:
            i, r, c = heapq.heappop(max_heap)
            if r == len(A)-1 and c == len(A[0])-1:
                return -i
            for d in directions:
                nr, nc = r+d[0], c+d[1]
                if 0 <= nr < len(A) and \
                   0 <= nc < len(A[0]) and \
                   (nr, nc) not in lookup:
                    heapq.heappush(max_heap, (-min(-i, A[nr][nc]), nr, nc))
                    lookup.add((nr, nc))    
        return -1
