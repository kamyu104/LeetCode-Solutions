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
            dist = [float("inf")]*len(adj)
            q = [u]
            dist[u] = 0
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[v] == dist[u]-1:  # v == p
                            continue
                        if dist[v] != INF:
                            return 1+dist[u]+dist[v]
                        dist[v] = dist[u]+1
                        new_q.append(v)                        
                    q = new_q
            return INF

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = min(bfs(u) for u in xrange(n))
        return result if result != INF else -1
