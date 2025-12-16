# Time:  O(n + elogn)
# Space: O(n + e)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minCostExcludingMax(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        L = 1
        def dijkstra(src, dst):
            dist = [[INF]*len(adj) for _ in xrange(L+1)]
            excl = 0
            dist[excl][src] = 0
            min_heap = [(dist[excl][src], src, excl)]
            while min_heap:
                curr, u, excl = heapq.heappop(min_heap)
                if curr > dist[excl][u]:
                    continue
                if u == dst:
                    break
                for v, w in adj[u]:
                    if excl+1 < len(dist) and curr < dist[excl+1][v]:
                        dist[1][v] = curr
                        heapq.heappush(min_heap, (dist[excl+1][v], v, 1))
                    if curr+w < dist[excl][v]:
                        dist[excl][v] = curr+w
                        heapq.heappush(min_heap, (dist[excl][v], v, excl))
            return dist[L][dst]

        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        return dijkstra(0, n-1)


# Time:  O(n + elogn)
# Space: O(n + e)
# dijkstra's algorithm
class Solution2(object):
    def minCostExcludingMax(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def dijkstra(u):
            dist = [INF]*len(adj)
            dist[u] = 0
            min_heap = [(dist[u], u)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr > dist[u]:
                    continue
                for v, w in adj[u]:
                    if not curr+w < dist[v]:
                        continue
                    dist[v] = curr+w
                    heapq.heappush(min_heap, (dist[v], v))
            return dist

        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        dist1 = dijkstra(0)
        dist2 = dijkstra(n-1)
        return min(dist1[i]+dist2[j] for u, v, _ in edges for i, j in ((u, v), (v, u)))
