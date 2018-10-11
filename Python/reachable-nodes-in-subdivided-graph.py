# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|),
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import collections
import heapq

class Solution(object):
    def reachableNodes(self, edges, M, N):
        """
        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        adj = [[] for _ in xrange(N)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        min_heap = [(0, 0)]
        best = collections.defaultdict(lambda: float("inf"))
        best[0] = 0
        count = collections.defaultdict(lambda: collections.defaultdict(int))
        result = 0
        while min_heap:
            curr_total, u = heapq.heappop(min_heap)  # O(|V|*log|V|) in total
            if best[u] < curr_total:
                continue
            result += 1
            for v, w in adj[u]:
                count[u][v] = min(w, M-curr_total)
                next_total = curr_total+w+1
                if next_total <= M and next_total < best[v]:
                    best[v] = next_total
                    heapq.heappush(min_heap, (next_total, v))  # binary heap O(|E|*log|V|) in total
                                                               # Fibonacci heap O(|E|) in total
        for u, v, w in edges:
            result += min(w, count[u][v]+count[v][u])
        return result

