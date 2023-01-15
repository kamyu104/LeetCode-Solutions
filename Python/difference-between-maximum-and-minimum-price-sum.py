# Time:  O(n)
# Space: O(n)

# iterative dfs, tree dp
class Solution(object):
    def maxOutput(self, n, edges, price):
        """
        :type n: int
        :type edges: List[List[int]]
        :type price: List[int]
        :rtype: int
        """
        def iter_dfs():
            result = 0
            stk = [(1, (0, -1, [price[0], 0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    stk.append((2, (u, p, ret, 0)))
                elif step == 2:
                    u, p, ret, i = args
                    if i == len(adj[u]):
                        continue
                    stk.append((2, (u, p, ret, i+1)))
                    v = adj[u][i]
                    if v == p:
                        continue
                    new_ret = [price[v], 0]  # [max_path_sum, max_path_sum_without_last_node]
                    stk.append((3, (u, new_ret, ret)))
                    stk.append((1, (v, u, new_ret)))
                elif step == 3:
                    u, new_ret, ret = args
                    result = max(result, ret[0]+new_ret[1], ret[1]+new_ret[0])
                    ret[0] = max(ret[0], new_ret[0]+price[u])
                    ret[1] = max(ret[1], new_ret[1]+price[u])
            return result
        
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs()


# Time:  O(n)
# Space: O(n)
# dfs, tree dp
class Solution2(object):
    def maxOutput(self, n, edges, price):
        """
        :type n: int
        :type edges: List[List[int]]
        :type price: List[int]
        :rtype: int
        """
        def dfs(u, p):
            dp = [price[u], 0]  # [max_path_sum, max_path_sum_without_last_node]
            for v in adj[u]:
                if v == p:
                    continue
                new_dp = dfs(v, u)
                result[0] = max(result[0], dp[0]+new_dp[1], dp[1]+new_dp[0])
                dp[0] = max(dp[0], new_dp[0]+price[u])
                dp[1] = max(dp[1], new_dp[1]+price[u])
            return dp
        
        result = [0]
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dfs(0, -1)
        return result[0]


# Time:  O(n)
# Space: O(n)
# iterative dfs, tree dp
class Solution3(object):
    def maxOutput(self, n, edges, price):
        """
        :type n: int
        :type edges: List[List[int]]
        :type price: List[int]
        :rtype: int
        """
        def iter_dfs():
            dp = [0]*n  # max_sum
            stk = [(1, 0, -1)]
            while stk:
                step, u, p = stk.pop()
                if step == 1:
                    stk.append((2, u, p))
                    for v in adj[u]:
                        if v == p:
                            continue
                        stk.append((1, v, u))
                elif step == 2:
                    dp[u] = price[u]
                    for v in adj[u]:
                        if v == p:
                            continue
                        dp[u] = max(dp[u], dp[v]+price[u])
            return dp
        
        def iter_dfs2():
            result = 0
            stk = [(0, -1, 0)]
            while stk:
                u, p, curr = stk.pop()
                result = max(result, curr, dp[u]-price[u])
                top2 = [[curr, p], [0, -1]]
                for v in adj[u]:
                    if v == p:
                        continue
                    curr = [dp[v], v]
                    for i in xrange(len(top2)):
                        if curr > top2[i]:
                            top2[i], curr = curr, top2[i]
                for v in adj[u]:
                    if v == p:
                        continue
                    stk.append((v, u, (top2[0][0] if top2[0][1] != v else top2[1][0])+price[u]))
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
class Solution4(object):
    def maxOutput(self, n, edges, price):
        """
        :type n: int
        :type edges: List[List[int]]
        :type price: List[int]
        :rtype: int
        """
        def dfs(u, p):
            dp[u] = price[u]
            for v in adj[u]:
                if v == p:
                    continue
                dp[u] = max(dp[u], dfs(v, u)+price[u])
            return dp[u]
        
        def dfs2(u, p, curr):
            result[0] = max(result[0], curr, dp[u]-price[u])
            top2 = [[curr, p], [0, -1]]
            for v in adj[u]:
                if v == p:
                    continue
                curr = [dp[v], v]
                for i in xrange(len(top2)):
                    if curr > top2[i]:
                        top2[i], curr = curr, top2[i]
            for v in adj[u]:
                if v == p:
                    continue
                dfs2(v, u, (top2[0][0] if top2[0][1] != v else top2[1][0])+price[u])
    
        result = [0]
        dp = [0]*n  # max_sum
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dfs(0, -1)
        dfs2(0, -1, 0)
        return result[0]
