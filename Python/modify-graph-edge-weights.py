# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import heapq


# dijkstra's algorithm
class Solution(object):
    def modifiedGraphEdges(self, n, edges, source, destination, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :type target: int
        :rtype: List[List[int]]
        """
        INF = 10**9
        def dijkstra(start, x):
            best = [INF]*len(adj)
            best[start] = 0
            min_heap = [(0, start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr > best[u]:
                    continue
                for v, w in adj[u]:       
                    if w == -1:
                        w = x
                    if curr+w >= best[v]:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return best
        
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        left = dijkstra(source, 1)
        if not (left[destination] <= target):
            return []
        right= dijkstra(destination, INF)
        if not (right[source] >= target):
            return []
        return [[u, v, (w if w != -1 else max(target-left[u]-right[v], target-left[v]-right[u], 1))] for u, v, w in edges]
