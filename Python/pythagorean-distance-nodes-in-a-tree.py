# Time:  O(n)
# Space: O(n)

# bfs
class Solution(object):
    def specialNodes(self, n, edges, x, y, z):
        """
        :type n: int
        :type edges: List[List[int]]
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        def bfs(x):
            dist = [-1]*n
            dist[x] = 0
            q = [x]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[v] != -1:
                            continue
                        dist[v] = dist[u]+1
                        new_q.append(v)
                q = new_q
            return dist

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dist1 = bfs(x)
        dist2 = bfs(y)
        dist3 = bfs(z)
        return sum(dist1[u]**2+dist2[u]**2+dist3[u]**2 == 2*max(dist1[u], dist2[u], dist3[u])**2 for u in xrange(n))
