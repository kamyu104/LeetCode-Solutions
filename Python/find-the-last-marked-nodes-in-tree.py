# Time:  O(n)
# Space: O(n)

# bfs
class Solution(object):
    def lastMarkedNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def bfs(root):
            new_root = -1
            dist = [-1]*len(adj)
            dist[root] = 0
            q = [root]
            while q:
                new_root = q[0]
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[v] != -1:
                            continue
                        dist[v] = dist[u]+1
                        new_q.append(v)
                q = new_q
            return dist, new_root
            
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        _, u = bfs(0)
        dist1, v = bfs(u)
        dist2, _ = bfs(v)
        return [u if dist1[w] > dist2[w] else v for w in xrange(len(adj))]


# Time:  O(n)
# Space: O(n)
# bfs
class Solution2(object):
    def lastMarkedNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def increase(x):
            return (x[0]+1, x[1])

        def bfs():
            dp = [[(0, u)]*2 for u in xrange(len(adj))]
            new_root = -1
            degree = map(len, adj)
            q = [u for u in xrange(len(degree)) if degree[u] == 1]
            while q:
                new_q = []
                for u in q:
                    if degree[u] == 0:
                        new_root = u
                        continue
                    degree[u] -= 1
                    for v in adj[u]:
                        if degree[v] == 0:
                            continue
                        curr = increase(dp[u][0])
                        for i in xrange(len(dp[v])):
                            if curr > dp[v][i]:
                                curr, dp[v][i] = dp[v][i], curr
                        degree[v] -= 1
                        if degree[v] == 1:
                            new_q.append(v)
                q = new_q
            return dp, new_root

        def bfs2(root):
            result = [-1]*len(adj)
            q = [(root, -1, (0, -1))]
            while q:
                new_q = []
                for u, p, curr in q:
                    result[u] = max(dp[u][0], curr)[1]
                    for v in adj[u]:
                        if v == p:
                            continue
                        new_q.append((v, u, increase(max(dp[u][dp[u][0][1] == dp[v][0][1]], curr))))
                q = new_q
            return result

        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp, u = bfs()
        return bfs2(u)


# Time:  O(n)
# Space: O(n)
# bfs
class Solution3(object):
    def lastMarkedNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def increase(x):
            return (x[0]+1, x[1])

        def topological_traversal():
            p = [-2]*len(adj)
            p[0] = -1
            topological_order = [0]
            for u in topological_order:
                for v in reversed(adj[u]):
                    if p[v] != -2:
                        continue
                    p[v] = u
                    topological_order.append(v)
            dp = [[(0, u)]*2 for u in xrange(len(adj))]
            for u in reversed(topological_order):
                for v in adj[u]:
                    if v == p[u]:
                        continue
                    curr = increase(dp[v][0])
                    for i in xrange(len(dp[u])):
                        if curr > dp[u][i]:
                            curr, dp[u][i] = dp[u][i], curr
            return dp

        def bfs():
            result = [-1]*len(adj)
            q = [(0, -1, (0, -1))]
            while q:
                new_q = []
                for u, p, curr in q:
                    result[u] = max(dp[u][0], curr)[1]
                    for v in adj[u]:
                        if v == p:
                            continue
                        new_q.append((v, u, increase(max(dp[u][dp[u][0][1] == dp[v][0][1]], curr))))
                q = new_q
            return result

        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp = topological_traversal()
        return bfs()


# Time:  O(n)
# Space: O(n)
# iterative dfs, tree dp
class Solution4(object):
    def lastMarkedNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def increase(x):
            return (x[0]+1, x[1])

        def iter_dfs1():
            dp = [[(0, u)]*2 for u in xrange(len(adj))]
            stk = [(1, (0, -1))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p = args
                    stk.append((2, (u, p, 0)))
                elif step == 2:
                    u, p, i = args
                    if i == len(adj[u]):
                        continue
                    stk.append((2, (u, p, i+1)))
                    v = adj[u][i]
                    if v == p:
                        continue
                    stk.append((3, (v, u)))
                    stk.append((1, (v, u)))
                elif step == 3:
                    v, u = args
                    curr = increase(dp[v][0])
                    for i in xrange(len(dp[u])):
                        if curr > dp[u][i]:
                            curr, dp[u][i] = dp[u][i], curr
            return dp

        def iter_dfs2():
            result = [-1]*len(adj)
            stk = [(0, -1, (0, -1))]
            while stk:
                u, p, curr = stk.pop()
                result[u] = max(dp[u][0], curr)[1]
                for v in reversed(adj[u]):
                    if v == p:
                        continue
                    stk.append((v, u, increase(max(dp[u][dp[u][0][1] == dp[v][0][1]], curr))))
            return result
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp = iter_dfs1()
        return iter_dfs2()


# Time:  O(n)
# Space: O(n)
# dfs, tree dp
class Solution5(object):
    def lastMarkedNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def increase(x):
            return (x[0]+1, x[1])

        def dfs1(u, p):
            for v in adj[u]:
                if v == p:
                    continue
                dfs1(v, u)
                curr = increase(dp[v][0])
                for i in xrange(len(dp[u])):
                    if curr > dp[u][i]:
                        curr, dp[u][i] = dp[u][i], curr

        def dfs2(u, p, curr):
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
