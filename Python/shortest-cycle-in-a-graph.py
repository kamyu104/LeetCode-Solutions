# Time:  O(n + e)
# Space: O(n + e)

import collections


# bfs
class Solution(object):
    def findShortestCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def iter_dfs():
            result = set(xrange(n))
            stk = [node for node in xrange(n) if in_degree[node] <= 1]
            while stk:
                u = stk.pop()
                result.remove(u)
                for v in adj[u]:
                    in_degree[v] -= 1
                    if in_degree[v] == 1:
                        stk.append(v)
            return result
    
        def bfs(u, dist, parent):
            result = INF
            dist[u] = 0
            parent[u] = -1
            q = [u]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if v in dist:
                            if v != parent[u]:  # v != p
                                l = 1
                                nu, nv = u, v
                                if dist[nu] < dist[nv]:
                                    l += 1
                                    nv = parent[nv]
                                elif dist[nu] > dist[nv]:
                                    l += 1
                                    nu = parent[nu]
                                while nu != nv:
                                    l += 2
                                    nv = parent[nv]
                                    nu = parent[nu]
                                result = min(result, l)
                            continue
                        dist[v] = dist[u]+1
                        parent[v] = u
                        new_q.append(v)                        
                    q = new_q
            return result
    
        adj = [[] for _ in xrange(n)]
        in_degree = collections.Counter()
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            in_degree[u] += 1
            in_degree[v] += 1
        in_cycle = iter_dfs()
        result = INF
        dist, parent = {}, {}
        for u in in_cycle:
            if u in dist:
                continue
            l = bfs(u, dist, parent)
            result = min(result, l)
        return result if result != INF else -1


# Time:  O(n^2)
# Space: O(n + e)
# bfs
class Solution2(object):
    def findShortestCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def bfs(u):
            dist = [float("inf")]*len(adj)
            dist[u] = 0
            q = [u]
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
