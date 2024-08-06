# Time:  O(n^2)
# Space: O(n^2)

# bfs
class Solution(object):
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def bfs(u, v):
            adj[u].append(v)
            q = [u]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[u]+1 >= dist[v]:
                            continue
                        dist[v] = dist[u]+1
                        new_q.append(v)
                q = new_q
            return dist[-1]

        adj = [[] for _ in xrange(n)]
        for u in xrange(n-1):
            adj[u].append(u+1)
        dist = range(n)
        return [bfs(u, v) for u, v in queries]


# Time:  O(n^2 * logn)
# Space: O(n^2)
import heapq


# dijkstra's algorithm
class Solution2(object):
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def dijkstra(u, v):
            adj[u].append((v, 1))
            min_heap = [(dist[u], u)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr > dist[u]:
                    continue
                for v, w in adj[u]:
                    if curr+w >= dist[v]:
                        continue
                    dist[v] = curr+w
                    heapq.heappush(min_heap, (dist[v], v))
            return dist[-1]

        adj = [[] for _ in xrange(n)]
        for u in xrange(n-1):
            adj[u].append((u+1, 1))
        dist = range(n)
        return [dijkstra(u, v) for u, v in queries]
