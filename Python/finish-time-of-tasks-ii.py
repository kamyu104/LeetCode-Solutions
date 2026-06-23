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
            stk = [(1, 0, -1)]
            while stk:
                step, u, p = stk.pop()
                if step == 1:
                    stk.append((2, u, p))
                    for v in reversed(adj[u]):
                        if v == p:
                            continue
                        stk.append((1, v, u))
                elif step == 2:
                    mx, mn = NEG_INF, POS_INF
                    for v in adj[u]:
                        if v == p:
                            continue
                        mx, mn = max(mx, dp[v]), min(mn, dp[v])
                    dp[u] = ((2*mx-mn) if mx is not NEG_INF else 0)+baseTime[u]
            return dp
        
        def iter_dfs2():
            def top2(a, b, x, cmp):
                if cmp(x, a):
                    a, b = x, a
                elif cmp(x, b):
                    b = x
                return a, b
    
            result = POS_INF
            stk = [(0, -1, NEG_INF)]
            while stk:
                u, p, t = stk.pop()
                mx1, mx2, mn1, mn2 = NEG_INF, NEG_INF, POS_INF, POS_INF
                for v in adj[u]:
                    x = dp[v] if v != p else t
                    mx1, mx2 = top2(mx1, mx2, x, lambda x, y: x > y)
                    mn1, mn2 = top2(mn1, mn2, x, lambda x, y: x < y)
                result = min(result, ((2*mx1-mn1) if mx1 is not NEG_INF else 0)+baseTime[u])
                for v in reversed(adj[u]):
                    if v == p:
                        continue
                    mx = mx1 if dp[v] != mx1 else mx2
                    mn = mn1 if dp[v] != mn1 else mn2
                    stk.append((v, u, ((2*mx-mn) if mx is not NEG_INF else 0)+baseTime[u]))
            return result
    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp = iter_dfs()
        return iter_dfs2()


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
        def dfs(u, p):
            mx, mn = NEG_INF, POS_INF
            for v in adj[u]:
                if v == p:
                    continue
                dfs(v, u)
                mx, mn = max(mx, dp[v]), min(mn, dp[v])
            dp[u] = ((2*mx-mn) if mx is not NEG_INF else 0)+baseTime[u]
        
        def dfs2(u, p, t):
            def top2(a, b, x, cmp):
                if cmp(x, a):
                    a, b = x, a
                elif cmp(x, b):
                    b = x
                return a, b

            mx1, mx2, mn1, mn2 = NEG_INF, NEG_INF, POS_INF, POS_INF
            for v in adj[u]:
                x = dp[v] if v != p else t
                mx1, mx2 = top2(mx1, mx2, x, lambda x, y: x > y)
                mn1, mn2 = top2(mn1, mn2, x, lambda x, y: x < y)
            result[0] = min(result[0], ((2*mx1-mn1) if mx1 is not NEG_INF else 0)+baseTime[u])
            for v in adj[u]:
                if v == p:
                    continue
                mx = mx1 if dp[v] != mx1 else mx2
                mn = mn1 if dp[v] != mn1 else mn2
                dfs2(v, u, ((2*mx-mn) if mx is not NEG_INF else 0)+baseTime[u])
    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp = [0]*n
        dfs(0, -1)
        result = [POS_INF]
        dfs2(0, -1, NEG_INF)
        return result[0]
