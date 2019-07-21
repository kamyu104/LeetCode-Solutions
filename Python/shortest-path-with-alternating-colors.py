# Time:  O(n + e), e is the number of red and blue edges
# Space: O(n + e)

import collections


class Solution(object):
    def shortestAlternatingPaths(self, n, red_edges, blue_edges):
        """
        :type n: int
        :type red_edges: List[List[int]]
        :type blue_edges: List[List[int]]
        :rtype: List[int]
        """
        neighbors = [[set() for _ in xrange(2)] for _ in xrange(n)]
        for i, j in red_edges:
            neighbors[i][0].add(j)
        for i, j in blue_edges:
            neighbors[i][1].add(j)
        INF = max(2*n-3, 0)+1
        dist = [[INF, INF] for i in xrange(n)]
        dist[0] = [0, 0]
        q = collections.deque([(0, 0), (0, 1)])
        while q:
            i, c = q.popleft()
            for j in neighbors[i][c]:
                if dist[j][c] != INF:
                    continue
                dist[j][c] = dist[i][1^c]+1
                q.append((j, 1^c))
        return [x if x != INF else -1 for x in map(min, dist)]
