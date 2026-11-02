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

        def iter_dfs():
            order = []
            parent = [-2]*len(values)
            parent[0] = -1
            stk = [0]
            while stk:
                u = stk.pop()
                order.append(u)
                for v, c in adj[u]:
                    if parent[v] != -2:
                        continue
                    parent[v] = u
                    stk.append(v)
            return order, parent

        INF = float("inf")
        adj = [[] for _ in xrange(len(values))]
        for u, v, c in edges:
            adj[u].append((v, c))
            adj[v].append((u, c))
        order, parent = iter_dfs()
        result = INF
        dp = [[INF]*2 for _ in xrange(len(values))]
        for u in reversed(order):
            p = parity(values[u])
            dp[u][p] = 0
            for v, c in adj[u]:
                if v == parent[u]:
                    continue
                result = min(result, min(dp[u][0]+dp[v][0], dp[u][1]+dp[v][1])+c)
                dp[u] = [min(dp[u][0], dp[v][p]+c), min(dp[u][1], dp[v][p^1]+c)]
        return result if result != INF else -1
