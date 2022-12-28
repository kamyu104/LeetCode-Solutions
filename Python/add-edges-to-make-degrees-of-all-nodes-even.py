# Time:  O(n)
# Space: O(n)

# graph
class Solution(object):
    def isPossible(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        adj = [set() for _ in xrange(n)]
        for u, v in edges:
            adj[u-1].add(v-1)
            adj[v-1].add(u-1)
        odds = [u for u in xrange(n) if len(adj[u])%2]
        if len(odds) == 0:
            return True
        if len(odds) == 2:
            return any(odds[0] not in adj[u] and odds[1] not in adj[u] for u in range(n))
        if len(odds) == 4:
            return ((odds[0] not in adj[odds[1]] and odds[2] not in adj[odds[3]]) or
                    (odds[0] not in adj[odds[2]] and odds[1] not in adj[odds[3]]) or
                    (odds[0] not in adj[odds[3]] and odds[1] not in adj[odds[2]]))
        return False
