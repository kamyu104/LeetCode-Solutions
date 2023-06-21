# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minimumDistance(self, n, edges, s, marked):
        """
        :type n: int
        :type edges: List[List[int]]
        :type s: int
        :type marked: List[int]
        :rtype: int
        """
        def dijkstra(start):
            best = [float("inf")]*len(adj)
            best[start] = 0
            min_heap = [(0, start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr > best[u]:
                    continue
                if u in target:
                    return curr
                for v, w in adj[u]:     
                    if curr+w >= best[v]:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return -1

        target = set(marked)
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
        return dijkstra(s)
