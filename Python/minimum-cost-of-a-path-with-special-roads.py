# Time:  O(n^2)
# Space: O(n^2)

import collections


# dijkstra's algorithm in a complete graph (no heap required)
class Solution(object):
    def minimumCost(self, start, target, specialRoads):
        """
        :type start: List[int]
        :type target: List[int]
        :type specialRoads: List[List[int]]
        :rtype: int
        """
        start, target = tuple(start), tuple(target)
        adj = collections.defaultdict(list, {target:[]})
        for x1, y1, x2, y2, c in specialRoads:
            adj[x1, y1].append((x2, y2, c))
        dist = {start:0}
        lookup = set()
        while len(lookup) != len(dist):
            d, x1, y1 = min((dist[x1, y1], x1, y1) for x1, y1 in dist.iterkeys() if (x1, y1) not in lookup)
            lookup.add((x1, y1))
            if (x1, y1) == target:
                return d
            for x2, y2, c in adj[x1, y1]:
                if not ((x2, y2) not in dist or dist[x2, y2] > d+c):
                    continue
                dist[x2, y2] = d+c
            for x2, y2 in adj.iterkeys():
                if not ((x2, y2) not in dist or dist[x2, y2] > d+abs(x2-x1)+abs(y2-y1)):
                    continue
                dist[x2, y2] = d+abs(x2-x1)+abs(y2-y1)


# Time:  O(n^2 * logn)
# Space: O(n^2)
import collections
import heapq
# dijkstra's algorithm
class Solution2(object):
    def minimumCost(self, start, target, specialRoads):
        """
        :type start: List[int]
        :type target: List[int]
        :type specialRoads: List[List[int]]
        :rtype: int
        """
        start, target = tuple(start), tuple(target)
        adj = collections.defaultdict(list, {target:[]})
        for x1, y1, x2, y2, c in specialRoads:
            adj[x1, y1].append((x2, y2, c))
        min_heap = [(0, start)]
        dist = {start:0}
        while min_heap:
            d, (x1, y1) = heapq.heappop(min_heap)
            if d > dist[x1, y1]:
                continue
            if (x1, y1) == target:
                return d
            for x2, y2, c in adj[x1, y1]:
                if not ((x2, y2) not in dist or dist[x2, y2] > d+c):
                    continue
                dist[x2, y2] = d+c
                heapq.heappush(min_heap, (dist[x2, y2], (x2, y2)))
            for x2, y2 in adj.iterkeys():
                if not ((x2, y2) not in dist or dist[x2, y2] > d+abs(x2-x1)+abs(y2-y1)):
                    continue
                dist[x2, y2] = d+abs(x2-x1)+abs(y2-y1)
                heapq.heappush(min_heap, (dist[x2, y2], (x2, y2)))
        return -1
