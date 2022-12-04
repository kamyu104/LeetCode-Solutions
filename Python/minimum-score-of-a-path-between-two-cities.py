# Time:  O(n + m), m = len(roads)
# Space: O(n + m)

# bfs
class Solution(object):
    def minScore(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        def bfs():
            lookup = [False]*len(adj)
            q = [0]
            lookup[0] = True
            while q:
                new_q = []
                for u in q:
                    for v, _ in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
            return lookup

        adj = [[] for _ in xrange(n)]
        for u, v, w in roads:
            adj[u-1].append((v-1, w))
            adj[v-1].append((u-1, w))
        lookup = bfs()
        return min(w for u, _, w in roads if lookup[u-1])
