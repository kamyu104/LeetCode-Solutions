# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import collections
import itertools
import heapq


class Solution(object):
    def maxProbability(self, n, edges, succProb, start, end):
        """
        :type n: int
        :type edges: List[List[int]]
        :type succProb: List[float]
        :type start: int
        :type end: int
        :rtype: float
        """
        adj = collections.defaultdict(list)
        for (u, v), p in itertools.izip(edges, succProb):
            adj[u].append((v, p))
            adj[v].append((u, p))
        max_heap = [(-1.0, start)]
        result, lookup = collections.defaultdict(float), set()
        result[start] = 1.0
        while max_heap and len(lookup) != len(adj):
            curr, u = heapq.heappop(max_heap)
            if u in lookup:
                continue
            lookup.add(u)
            for v, w in adj[u]:
                if v in lookup:
                    continue
                if v in result and result[v] >= -curr*w:
                    continue
                result[v] = -curr*w
                heapq.heappush(max_heap, (-result[v], v))
        return result[end]
