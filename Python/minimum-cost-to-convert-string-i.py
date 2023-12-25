# Time:  O(o + k * eloge + n), k = len(set(original)), e is the number of edges reachable from a given node u
# Space: O(o + k * v), v is the number of nodes reachable from a given node u

import collections
import heapq


# dijkstra's algorithm, memoization
class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        INF = float("inf")
        def dijkstra(start):
            best = collections.defaultdict(lambda: INF)
            best[start] = 0
            min_heap = [(0, start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr > best[u]:
                    continue
                for v, w in dist[u].iteritems():     
                    if curr+w >= best[v]:
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return best
        
        def memoization(u, v):
            if u not in lookup:
                lookup[u] = dijkstra(u)
            return lookup[u][v]

        dist = collections.defaultdict(lambda: collections.defaultdict(lambda: INF))
        for i in xrange(len(original)):
            u, v = ord(original[i])-ord('a'), ord(changed[i])-ord('a')
            dist[u][v] = min(dist[u][v], cost[i])
        lookup = {}
        result = sum(memoization(ord(source[i])-ord('a'), ord(target[i])-ord('a')) for i in xrange(len(source)))
        return result if result != INF else -1


# Time:  O(o + 26^3 + n)
# Space: O(o + 26^2)
# Floyd-Warshall algorithm 
class Solution2(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        INF = float("inf")
        def floydWarshall(dist):
            for k in xrange(len(dist)):
                for i in xrange(len(dist)):
                    for j in xrange(len(dist[i])):
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

        dist = [[0 if u == v else INF for v in xrange(26)] for u in xrange(26)]
        for i in xrange(len(original)):
            u, v = ord(original[i])-ord('a'), ord(changed[i])-ord('a')
            dist[u][v] = min(dist[u][v], cost[i])
        floydWarshall(dist)
        result = sum(dist[ord(source[i])-ord('a')][ord(target[i])-ord('a')] for i in xrange(len(source)))
        return result if result != INF else -1
