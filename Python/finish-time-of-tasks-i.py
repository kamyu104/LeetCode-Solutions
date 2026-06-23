# Time:  O(n)
# Space: O(n)

# iterative dfs, tree dp
class Solution(object):
    def finishTime(self, n, edges, baseTime):
        """
        :type n: int
        :type edges: List[List[int]]
        :type baseTime: List[int]
        :rtype: int
        """
        POS_INF, NEG_INF = float("inf"), float("-inf")
        def iter_dfs():
            dp = [0]*n
            stk = [(1, 0)]
            while stk:
                step, u = stk.pop()
                if step == 1:
                    stk.append((2, u))
                    for v in reversed(adj[u]):
                        stk.append((1, v))
                elif step == 2:
                    mx, mn = NEG_INF, POS_INF
                    for v in adj[u]:
                        mx, mn = max(mx, dp[v]), min(mn, dp[v])
                    dp[u] = ((2*mx-mn) if mx is not NEG_INF else 0)+baseTime[u]
            return dp[0]
    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
        return iter_dfs()
    

# Time:  O(n)
# Space: O(n)
# dfs, tree dp
class Solution2(object):
    def finishTime(self, n, edges, baseTime):
        """
        :type n: int
        :type edges: List[List[int]]
        :type baseTime: List[int]
        :rtype: int
        """
        POS_INF, NEG_INF = float("inf"), float("-inf")
        def dfs(u):
            mx, mn = NEG_INF, POS_INF
            for v in adj[u]:
                ret = dfs(v)
                mx, mn = max(mx, ret), min(mn, ret)
            return ((2*mx-mn) if mx is not NEG_INF else 0)+baseTime[u]
    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
        return dfs(0)
    
