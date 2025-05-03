# Time:  O(n)
# Space: O(n)

# bfs
class Solution(object):
    def baseUnitConversions(self, conversions):
        """
        :type conversions: List[List[int]]
        :rtype: List[int]
        """
        MOD = 10**9+7
        adj = [[] for _ in xrange(len(conversions)+1)]
        for u, v, w in conversions:
            adj[u].append((v, w))
        result = [0]*len(adj)
        result[0] = 1
        q = [0]
        while q:
            new_q = []
            for u in q:
                for v, w in adj[u]:
                    result[v] = (result[u]*w)%MOD
                    new_q.append(v)
            q = new_q
        return result
