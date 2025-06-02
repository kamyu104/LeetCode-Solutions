# Time:  O(n)
# Space: O(n)

# bfs, combinatorics
class Solution(object):
    def assignEdgeWeights(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        def bfs():
            lookup = [False]*len(adj)
            lookup[0] = True
            d = -1
            q = [0]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
                d += 1
            return d

        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        return pow(2, bfs()-1, MOD)
