# Time:  O(m * n * log(m * n))
# Space: O(m * n)

import heapq


# Dijkstra algorithm solution
class Solution(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        dst = (len(heights)-1, len(heights[0])-1)
        dist = [[float("inf")]*len(heights[0]) for _ in xrange(len(heights))]
        min_heap = [(0, 0, 0)]
        while min_heap:
            d, r, c = heapq.heappop(min_heap)
            if (r, c) == dst:
                return d
            for dr, dc in directions:
                nr, nc = r+dr, c+dc
                if not (0 <= nr < len(heights) and 0 <= nc < len(heights[0])):
                    continue
                nd = max(d, abs(heights[nr][nc]-heights[r][c]))
                if nd < dist[nr][nc]:
                    dist[nr][nc] = nd
                    heapq.heappush(min_heap, (nd, nr, nc))
        return -1


# Time:  O(m * n * logh)
# Space: O(m * n)
# bi-bfs solution
class Solution2(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def check(heights, x):  # bi-bfs
            lookup = [[False]*len(heights[0]) for _ in xrange(len(heights))]
            left, right = {(0, 0)}, {(len(heights)-1, len(heights[0])-1)}
            while left:
                for r, c in left:
                    lookup[r][c] = True
                new_left = set()
                for r, c in left:
                    if (r, c) in right: 
                        return True
                    for dr, dc in directions:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(heights) and
                                0 <= nc < len(heights[0]) and
                                abs(heights[nr][nc]-heights[r][c]) <= x and
                                not lookup[nr][nc]):
                            continue
                        new_left.add((nr, nc))
                left = new_left
                if len(left) > len(right): 
                    left, right = right, left
            return False            
        

        left, right = 0, 10**6
        while left <= right:
            mid = left + (right-left)//2
            if check(heights, mid):
                right = mid-1
            else:
                left = mid+1
        return left


# Time:  O(m * n * logh)
# Space: O(m * n)
import collections


# bfs solution
class Solution3(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def check(heights, x):
            lookup = [[False]*len(heights[0]) for _ in xrange(len(heights))]
            q = collections.deque([(0, 0)])
            while q:
                r, c = q.popleft()
                if (r, c) == (len(heights)-1, len(heights[0])-1):
                    return True
                for dr, dc in directions:
                    nr, nc = r+dr, c+dc
                    if not (0 <= nr < len(heights) and
                                0 <= nc < len(heights[0]) and
                                abs(heights[nr][nc]-heights[r][c]) <= x and
                                not lookup[nr][nc]):
                            continue
                    lookup[nr][nc] = True
                    q.append((nr, nc))
            return False            
        
        left, right = 0, 10**6
        while left <= right:
            mid = left + (right-left)//2
            if check(heights, mid):
                right = mid-1
            else:
                left = mid+1
        return left
