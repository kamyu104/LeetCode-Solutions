# Time:  O(n + elogn)
# Space: O(n + e)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minCost(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
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
                if u == len(adj)-1:
                    return curr
                for v, w in adj[u]:
                    if not (best[v] > curr+w):
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return -1

        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, 2*w))
        return dijkstra()
