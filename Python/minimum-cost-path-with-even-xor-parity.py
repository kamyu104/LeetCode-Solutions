# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def minActivationCost(self, edges, values):
        """
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        INF = float("inf")
        def popcount(x):
            return bin(x).count('1')

        def parity(x):
            return popcount(x)%2

        mn = [INF]*len(values)
        result = INF
        for u, v, c in edges:
            i, j = parity(values[u]), parity(values[v])
            if i == j:
                result = min(result, c)
                continue
            if i > j:
                u, v = v, u
            result = min(result, mn[u]+c)
            mn[u] = min(mn[u], c)
        return result if result != INF else -1


# Time:  O(n)
# Space: O(n)
# iterative dfs, tree dp
class Solution2(object):
    def minActivationCost(self, edges, values):
        """
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        INF = float("inf")
        def popcount(x):
            return bin(x).count('1')

        def parity(x):
            return popcount(x)%2

        INF = float("inf")
        adj = [[] for _ in xrange(len(values))]
        for u, v, c in edges:
            adj[u].append((v, c))
            adj[v].append((u, c))
        order = []
        parent, cost = [-2]*len(values), [-1]*len(values)
        parent[0], cost[0] = -1, 0
        stk = [0]
        while stk:
            u = stk.pop()
            order.append(u)
            for v, c in adj[u]:
                if parent[v] != -2:
                    continue
                parent[v], cost[v] = u, c
                stk.append(v)
        dp = [[0, INF] if parity(x) == 0 else [INF, 0] for x in values]
        mn = INF
        for i in reversed(xrange(1, len(order))):
            v = order[i]
            u, c, p = parent[v], cost[v], parity(values[parent[v]])
            mn = min(mn, min(dp[u][0]+dp[v][0], dp[u][1]+dp[v][1])+c)
            dp[u] = [min(dp[u][0], dp[v][p]+c), min(dp[u][1], dp[v][p^1]+c)]
        return mn if mn != INF else -1
