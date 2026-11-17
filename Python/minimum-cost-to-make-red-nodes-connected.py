# Time:  O(n)
# Space: O(n)

# iterative dfs, tree dp
class Solution(object):
    def minCost(self, n, colors, edges):
        """
        :type n: int
        :type colors: str
        :type edges: List[List[int]]
        :rtype: int
        """
        def iter_dfs():
            order = []
            parent = [-2]*n
            parent[0] = -1
            stk = [0]
            while stk:
                u = stk.pop()
                order.append(u)
                for v in adj[u]:
                    if parent[v] != -2:
                        continue
                    parent[v] = u
                    stk.append(v)
            return order, parent

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        order, parent = iter_dfs()
        total = mn = 0
        dp1, dp2 = [1]*n, [0]*n
        for u in reversed(order):
            for v in adj[u]:
                if v == parent[u]:
                    continue
                dp1[u] += dp1[v]
                if dp2[v] < 0:
                    dp2[u] += dp2[v]
            if colors[u] == 'R':
                total += dp1[u]
                dp2[u] += -dp1[u]
            else:
                dp2[u] += dp1[u]
            if dp2[u] < mn:
                mn = dp2[u]
        return total+mn
