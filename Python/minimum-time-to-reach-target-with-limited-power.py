# Time:  O((n * p + e * p) * log(n * p))
# Space: O(n * p)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minTimeMaxPower(self, n, edges, power, cost, source, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type power: int
        :type cost: List[int]
        :type source: int
        :type target: int
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
        dist = [[float("inf")]*(power+1) for _ in xrange(n)]
        dist[source][power] = 0
        min_heap = [(dist[source][power] , -power, source)]
        while min_heap:
            t, p, u = heapq.heappop(min_heap)
            p = -p
            if t > dist[u][p]:
                continue
            if u == target:
                return [t, p]
            np = p-cost[u]
            if np < 0:
                continue
            for v, w in adj[u]:
                if t+w >= dist[v][np]:
                    continue
                dist[v][np] = t+w
                heapq.heappush(min_heap, (dist[v][np], -np, v))
        return [-1, -1]
