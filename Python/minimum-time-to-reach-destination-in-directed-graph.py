# Time:  O(n + elogn)
# Space: O(n + e)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minTime(self, n, edges):
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
                for v, s, e in adj[u]:
                    if curr > e:
                        continue
                    if not (best[v] > max(curr, s)+1):
                        continue
                    best[v] = max(curr, s)+1
                    heapq.heappush(min_heap, (best[v], v))
            return -1

        adj = [[] for _ in xrange(n)]
        for u, v, s, e in edges:
            adj[u].append((v, s, e))
        return dijkstra()
