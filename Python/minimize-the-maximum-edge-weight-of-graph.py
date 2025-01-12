# Time:  O(nlogn + e)
# Space: O(n + e)

import collections
import heapq


# dijkstra's algorithm
class Solution(object):
    def minMaxWeight(self, n, edges, threshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        def dijkstra():
            best = [float("inf")]*len(adj)
            best[0] = 0
            min_heap = [(best[0], 0)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr != best[u]:
                    continue
                for v, w in adj[u].iteritems():
                    if not (max(curr, w) < best[v]):
                        continue
                    best[v] = max(curr, w)
                    heapq.heappush(min_heap, (best[v], v))
            result = max(best)
            return result if result != float("inf") else -1

        adj = [collections.defaultdict(lambda: float("inf")) for _ in xrange(n)]
        for i, j, w in edges:
            adj[j][i] = min(adj[j][i], w)
        return dijkstra()


# Time:  O(nlogn + e)
# Space: O(n + e)
import collections
import heapq


# prim's algorithm
class Solution2(object):
    def minMaxWeight(self, n, edges, threshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        def prim():
            best = [float("inf")]*len(adj)
            min_heap = [(0, 0)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if best[u] != float("inf"):
                    continue
                best[u] = curr
                for v, w in adj[u].iteritems():
                    if best[v] != float("inf"):
                        continue
                    heapq.heappush(min_heap, (w, v))
            result = max(best)
            return result if result != float("inf") else -1

        adj = [collections.defaultdict(lambda: float("inf")) for _ in xrange(n)]
        for i, j, w in edges:
            adj[j][i] = min(adj[j][i], w)
        return prim()


# Time:  O(nlogw + e)
# Space: O(n + e)
import collections


# binary search, bfs
class Solution3(object):
    def minMaxWeight(self, n, edges, threshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(x):
            cnt = len(adj)
            lookup = [False]*len(adj)
            lookup[0] = True
            cnt -= 1
            q = [0]
            while q:
                new_q = []
                for u in q:
                    for v, w in adj[u].iteritems():
                        if w > x or lookup[v]:
                            continue
                        lookup[v] = True
                        cnt -= 1
                        new_q.append(v)
                q = new_q
            return cnt == 0
    
        adj = [collections.defaultdict(lambda: float("inf")) for _ in xrange(n)]
        for i, j, w in edges:
            adj[j][i] = min(adj[j][i], w)
        left, right = min(w for _, _, w in edges), max(w for _, _, w in edges)
        result = binary_search(left, right, check)
        return result if result <= right else -1
