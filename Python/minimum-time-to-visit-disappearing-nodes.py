# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minimumTime(self, n, edges, disappear):
        """
        :type n: int
        :type edges: List[List[int]]
        :type disappear: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        def modified_dijkstra(start):
            best = [-1]*n
            best[start] = 0
            min_heap = [(best[start], start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr != best[u]:
                    continue
                for v, w in adj[u]: 
                    if not curr+w < min(best[v] if best[v] != -1 else INF, disappear[v]):  # modified
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return best
        
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        return modified_dijkstra(0)
