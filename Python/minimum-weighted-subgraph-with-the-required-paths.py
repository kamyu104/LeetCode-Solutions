# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|),
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import heapq


# dijkstra's algorithm
class Solution(object):
    def minimumWeight(self, n, edges, src1, src2, dest):
        """
        :type n: int
        :type edges: List[List[int]]
        :type src1: int
        :type src2: int
        :type dest: int
        :rtype: int
        """
        def dijkstra(adj, start):
            best = [float("inf")]*len(adj)
            best[start] = 0
            min_heap = [(0, start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if best[u] < curr:
                    continue
                for v, w in adj[u]:                
                    if best[v] <= curr+w:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (curr+w, v))
            return best
    
        adj1, adj2 = [[[] for _ in xrange(n)] for _ in xrange(2)]
        for u, v, w in edges:
            adj1[u].append((v, w))
            adj2[v].append((u, w))
        dist1 = dijkstra(adj1, src1)
        dist2 = dijkstra(adj1, src2)
        dist3 = dijkstra(adj2, dest)
        result = min(dist1[i]+dist2[i]+dist3[i] for i in xrange(n))
        return result if result != float("inf") else -1
