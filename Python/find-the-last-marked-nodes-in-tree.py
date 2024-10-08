# Time:  O(n)
# Space: O(n)

# tree dp
class Solution(object):
    def lastMarkedNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def dfs1(u, p):
            for v in adj[u]:
                if v == p:
                    continue
                dfs1(v, u)
                tmp = (dp[v][0][0]+1, dp[v][0][1])
                for i in xrange(len(dp[u])):
                    if tmp > dp[u][i]:
                        tmp, dp[u][i] = dp[u][i], tmp

        def dfs2(u, p, curr):
            def increase(x):
                return (x[0]+1, x[1])
    
            for v in adj[u]:
                if v == p:
                    continue
                dfs2(v, u, increase(max(dp[u][dp[u][0][1] == dp[v][0][1]], curr)))
            result[u] = max(dp[u][0], curr)[1]
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp = [[(0, u)]*2 for u in xrange(len(adj))]
        dfs1(0, -1)
        result = [-1]*len(adj)
        dfs2(0, -1, (0, -1))
        return result
