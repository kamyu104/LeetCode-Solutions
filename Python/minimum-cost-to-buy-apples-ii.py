# Time:  O(n * (n + elogn))
# Space: O(n + e)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minCost(self, n, prices, roads):
        """
        :type n: int
        :type prices: List[int]
        :type roads: List[List[int]]
        :rtype: List[int]
        """
        INF = float("inf")
        def dijkstra(start, target):
            best = [INF]*len(adj)
            best[start] = 0
            min_heap = [(best[start], start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr != best[u]:
                    continue
                if u == target:
                    return curr
                for v, w in adj[u]:     
                    if best[v] <= curr+w:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return INF

        adj = [[] for _ in xrange(2*n)]
        for u, v, c, t in roads:
            adj[u].append((v, c))
            adj[v].append((u, c))
            adj[u+n].append((v+n, c*t))
            adj[v+n].append((u+n, c*t))
        for i in xrange(n):
            adj[i].append((i+n , prices[i]))
        return [dijkstra(i, i+n) for i in xrange(n)]


# Time:  O(n * (n + elogn))
# Space: O(n + e)
import heapq


# dijkstra's algorithm
class Solution2(object):
    def minCost(self, n, prices, roads):
        """
        :type n: int
        :type prices: List[int]
        :type roads: List[List[int]]
        :rtype: List[int]
        """
        INF = float("inf")
        def dijkstra(adj, start):
            best = [INF]*len(adj)
            best[start] = 0
            min_heap = [(best[start], start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr != best[u]:
                    continue
                for v, w in adj[u]:     
                    if best[v] <= curr+w:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return best

        adj = [[[] for _ in xrange(n)] for _ in xrange(2)]
        for u, v, c, t in roads:
            adj[0][u].append((v, c))
            adj[0][v].append((u, c))
            adj[1][u].append((v, c*t))
            adj[1][v].append((u, c*t))
        result = [0]*n
        for i in xrange(n):
            dist = [dijkstra(adj[j], i) for j in xrange(2)]
            result[i] = min(dist[0][j]+prices[j]+dist[1][j] for j in xrange(n))
        return result
