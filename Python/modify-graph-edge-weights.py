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
        def dijkstra(start, x):
            best = [target+1]*len(adj)
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
        right= dijkstra(destination, target+1)
        if not (right[source] >= target):
            return []
        for e in edges:
            if e[2] == -1:
                e[2] = max(target-left[e[0]]-right[e[1]], target-left[e[1]]-right[e[0]], 1)
        return edges
