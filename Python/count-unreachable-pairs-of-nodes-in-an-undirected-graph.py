# Time:  O(n)
# Space: O(n)

# flood fill, bfs, math
class Solution(object):
    def countPairs(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def bfs(adj, u, lookup):
            q = [u]
            lookup[u] = 1
            result = 1
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = 1
                        result += 1
                        new_q.append(v)
                q = new_q
            return result
        
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lookup = [0]*n
        result = 0
        for u in xrange(n):
            if lookup[u]:
                continue
            cnt = bfs(adj, u, lookup)
            result += cnt*(n-cnt)
            n -= cnt
        return result
