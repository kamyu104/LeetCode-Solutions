# Time:  O(n)
# Space: O(n)

# bfs, constructive algorithms
class Solution(object):
    def constructGridLayout(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        def bfs(u):
            dist = [0]*n
            dist[u] = 1
            q = [u]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[v]:
                            continue
                        dist[v] = dist[u]+1
                        new_q.append(v)
                q = new_q
            return dist
    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        mn = min(len(x) for x in adj)
        corners = [u for u in xrange(n) if len(adj[u]) == mn]
        dist1 = bfs(corners[0])
        corners.sort(key=lambda x: dist1[x])
        dist2 = bfs(corners[1])
        c = dist1[corners[1]]
        r = n//c
        result = [[0]*c for _ in range(r)]
        for u in xrange(n):
            i = ((dist1[u]+dist2[u])-(1+c))//2
            j = (dist1[u]-1)-i
            result[i][j] = u
        return result
