# Time:  O(e * k * log(n * k))
# Space: O(n * k + e)

import heapq


# dijkstra's algorithms
class Solution(object):
    def shortestPath(self, n, edges, labels, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :type k: int
        :rtype: int
        """
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
        dist = [[float("inf")]*k for _ in xrange(n)]
        dist[0][0] = 0
        min_heap = [(dist[0][0], 0, 0)]
        while min_heap:
            d, u, c = heapq.heappop(min_heap)
            if d > dist[u][c]:
                continue
            if u == n-1:
                return d
            for v, w in adj[u]:
                nc = c+1 if labels[v] == labels[u] else 0
                if not (nc < k and d+w < dist[v][nc]):
                    continue
                dist[v][nc] = d+w
                heapq.heappush(min_heap, (dist[v][nc], v, nc))
        return -1
