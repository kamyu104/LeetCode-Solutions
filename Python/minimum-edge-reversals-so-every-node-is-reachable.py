# Time:  O(n)
# Space: O(n)

# iterative dfs, tree dp
class Solution(object):
    def minEdgeReversals(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def iter_dfs1():
            result = 0
            stk = [(0, -1)]
            while stk:
                u, p = stk.pop()
                for v in adj[u].iterkeys():
                    if v == p:
                        continue
                    result += adj[u][v]
                    stk.append((v, u))
            return result

        def iter_dfs2(curr):
            result = [-1]*n
            stk = [(0, curr)]
            while stk:
                u, curr = stk.pop()
                result[u] = curr
                for v in adj[u].iterkeys():
                    if result[v] == -1:
                        stk.append((v, curr-adj[u][v]+adj[v][u]))
            return result
    
        adj = collections.defaultdict(dict)
        for u, v in edges:
            adj[u][v] = 0
            adj[v][u] = 1
        return iter_dfs2(iter_dfs1())
        

# Time:  O(n)
# Space: O(n)
# dfs, tree dp
class Solution2(object):
    def minEdgeReversals(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def dfs1(u, p):
            return sum(adj[u][v]+dfs1(v, u) for v in adj[u] if v != p)

        def dfs2(u, curr):
            result[u] = curr
            for v in adj[u]:
                if result[v] == -1:
                    dfs2(v, curr-adj[u][v]+adj[v][u])
    
        adj = collections.defaultdict(dict)
        for u, v in edges:
            adj[u][v] = 0
            adj[v][u] = 1
        result = [-1]*n
        dfs2(0, dfs1(0, -1))
        return result
