# Time:  O(n * rlogn), r = len(roads)
# Space: O(n)

import itertools
import heapq


# dijkstra's algorithm
class Solution(object):
    def minCost(self, n, roads, appleCost, k):
        """
        :type n: int
        :type roads: List[List[int]]
        :type appleCost: List[int]
        :type k: int
        :rtype: List[int]
        """
        def dijkstra(start):
            best = [float("inf")]*len(adj)
            best[start] = 0
            min_heap = [(0, start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if best[u] < curr:
                    continue
                for v, w in adj[u]:                
                    if best[v] <= curr+w:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (curr+w, v))
            return best

        adj = [[] for _ in xrange(n)]
        for a, b, c in roads:
            adj[a-1].append((b-1, c))
            adj[b-1].append((a-1, c))
        return [min(a+d*(k+1) for a, d in itertools.izip(appleCost, dijkstra(u))) for u in xrange(n)]
