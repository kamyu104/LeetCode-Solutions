# Time:  O(n)
# Space: O(n)

# bfs
class Solution(object):
    def reachableNodes(self, n, edges, restricted):
        """
        :type n: int
        :type edges: List[List[int]]
        :type restricted: List[int]
        :rtype: int
        """
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = 0
        lookup = [False]*n
        for x in restricted:
            lookup[x] = True
        q = [0]
        lookup[0] = True
        while q:
            new_q = []
            for u in q:
                result += 1
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    lookup[v] = True
                    new_q.append(v)
            q = new_q
        return result
