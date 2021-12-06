# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import collections
import heapq


class Solution(object):
    def minimumCost(self, n, highways, discounts):
        """
        :type n: int
        :type highways: List[List[int]]
        :type discounts: int
        :rtype: int
        """
        adj = [[] for _ in xrange(n)]
        for u, v, w in highways:
            adj[u].append((v, w))
            adj[v].append((u, w))
        src, dst = 0, n-1
        best = collections.defaultdict(lambda: collections.defaultdict(lambda: float("inf")))
        best[src][discounts] = 0
        min_heap = [(0, src, discounts)]
        while min_heap:
            result, u, k = heapq.heappop(min_heap)
            if best[u][k] < result:
                continue
            if u == dst:
                return result
            for v, w in adj[u]:
                if result+w < best[v][k]:
                    best[v][k] = result+w                    
                    heapq.heappush(min_heap, (result+w, v, k))
                if k > 0 and result+w//2 < best[v][k-1]:
                    best[v][k-1] = result+w//2                   
                    heapq.heappush(min_heap, (result+w//2, v, k-1))
        return -1
