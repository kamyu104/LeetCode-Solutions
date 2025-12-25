# Time:  O(n)
# Space: O(n)

# tree diameter, bfs
class Solution(object):
    def findSpecialNodes(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: str
        """
        def bfs(u):
            lookup = [False]*len(adj)
            lookup[u] = True
            q = [u]
            new_q = []
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q, new_q = new_q, q
            return new_q
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = ['0']*n
        far = bfs(0)
        for u in far:
            result[u] = '1'
        for u in bfs(far[0]):
            result[u] = '1'
        return "".join(result)
