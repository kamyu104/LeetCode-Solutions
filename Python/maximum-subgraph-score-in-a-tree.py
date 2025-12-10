# Time:  O(n)
# Space: O(n)

# bfs, tree dp
class Solution(object):
    def maxSubgraphScore(self, n, edges, good):
        """
        :type n: int
        :type edges: List[List[int]]
        :type good: List[int]
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        parent = [-1]*n
        q = [0]
        for u in q:
            for v in adj[u]:
                if v == parent[u]:
                    continue
                parent[v] = u
                q.append(v)
        dp = [1 if x else -1 for x in good]
        for u in reversed(q):
            if parent[u] == -1:
                continue
            dp[parent[u]] += max(dp[u], 0)
        for u in q:
            if parent[u] == -1:
                continue
            dp[u] += max(dp[parent[u]]-max(dp[u], 0), 0)
        return dp
