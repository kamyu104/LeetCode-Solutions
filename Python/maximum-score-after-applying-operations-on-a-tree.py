# Time:  O(n)
# Space: O(n)

# iterative dfs, tree dp
class Solution(object):
    def maximumScoreAfterOperations(self, edges, values):
        """
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        def iter_dfs():
            dp = [0]*len(values)
            stk = [(1, 0, -1)]
            while stk:
                step, u, p = stk.pop() 
                if step == 1:
                    if len(adj[u]) == (1 if u else 0):
                        dp[u] = values[u]
                        continue
                    stk.append((2, u, p))
                    for v in reversed(adj[u]):
                        if v != p:
                            stk.append((1, v, u))
                elif step == 2:
                    dp[u] = min(sum(dp[v] for v in adj[u] if v != p), values[u])  # min(pick u, not pick u)
            return dp[0]

        adj = [[] for _ in xrange(len(values))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return sum(values)-iter_dfs()


# Time:  O(n)
# Space: O(n)
# dfs, tree dp
class Solution2(object):
    def maximumScoreAfterOperations(self, edges, values):
        """
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        def dfs(u, p):
            if len(adj[u]) == (1 if u else 0):
                return values[u]
            return min(sum(dfs(v, u) for v in adj[u] if v != p), values[u])  # min(pick u, not pick u)

        adj = [[] for _ in xrange(len(values))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return sum(values)-dfs(0, -1)
