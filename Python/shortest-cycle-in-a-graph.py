# Time:  O(n^2)
# Space: O(n + e)

# bfs
class Solution(object):
    def findShortestCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def bfs(u):
            result = INF
            dist = [float("inf")]*len(adj)
            dist[u] = 0
            q = [u]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[v] != INF:
                            if dist[v] in (dist[u], dist[u]+1):
                                result = min(result, 1+dist[u]+dist[v])
                            continue
                        dist[v] = dist[u]+1
                        new_q.append(v)
                if result != INF:
                    break
                q = new_q
            return result

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = min(bfs(u) for u in xrange(n))
        return result if result != INF else -1
