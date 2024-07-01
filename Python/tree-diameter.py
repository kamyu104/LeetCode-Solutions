# Time:  O(|V| + |E|)
# Space: O(|E|)

# iterative dfs
class Solution(object):
    def treeDiameter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def iter_dfs():
            result = 0
            stk = [(1, (0, -1, [0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    for v in reversed(adj[u]):
                        if v == p:
                            continue
                        ret2 = [0]
                        stk.append((2, (ret2, ret)))
                        stk.append((1, (v, u, ret2)))
                elif step == 2:
                    ret2, ret = args
                    result = max(result, ret[0]+(ret2[0]+1))
                    ret[0] = max(ret[0], ret2[0]+1)
            return result
        
        adj = [[] for _ in range(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs()


# Time:  O(|V| + |E|)
# Space: O(|E|)
# dfs
class Solution2(object):
    def treeDiameter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def dfs(u, p):
            mx = 0
            for v in adj[u]:
                if v == p:
                    continue
                curr = dfs(v, u)
                result[0] = max(result[0], mx+(curr+1))
                mx = max(mx, curr+1)
            return mx
            
        adj = [[] for _ in range(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = [0]
        dfs(0, -1)
        return result[0]


# Time:  O(|V| + |E|)
# Space: O(|E|)
# bfs, tree dp
class Solution3(object):
    def treeDiameter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def bfs():
            result = 0
            dp = [0]*len(adj)
            degree = map(len, adj)
            q = [u for u in xrange(len(degree)) if degree[u] == 1]
            while q:
                new_q = []
                for u in q:
                    if degree[u] == 0:
                        continue
                    degree[u] -= 1
                    for v in adj[u]:
                        if degree[v] == 0:
                            continue
                        result = max(result, dp[v]+(dp[u]+1))
                        dp[v] = max(dp[v], (dp[u]+1))
                        degree[v] -= 1
                        if degree[v] == 1:
                            new_q.append(v)
                q = new_q
            return result
        
        adj = [[] for _ in range(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return bfs()


# Time:  O(|V| + |E|)
# Space: O(|E|)
# bfs
class Solution4(object):
    def treeDiameter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def bfs(root):
            d = new_root = -1
            lookup = [False]*len(adj)
            lookup[root] = True
            q = [root]
            while q:
                d, new_root = d+1, q[0]
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
            return d, new_root
        
        adj = [[] for _ in range(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        _, root = bfs(0)
        d, _ = bfs(root)
        return d
