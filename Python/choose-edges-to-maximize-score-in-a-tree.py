# Time:  O(n)
# Space: O(n)

# iterative dfs, tree dp
class Solution(object):
    def maxScore(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def iter_dfs():
            result = [(0, 0) for _ in xrange(len(adj))]
            stk = [(1, 0)]
            while stk:
                step, u = stk.pop()
                if step == 1:
                    if not adj[u]:
                        continue
                    stk.append((2, u))
                    for v, _ in adj[u]:
                        stk.append((1, v))
                elif step == 2:
                    without_u = sum(max(result[v]) for v, w in adj[u])
                    with_u = max(without_u-max(result[v])+(result[v][1]+w) for v, w in adj[u])
                    result[u] = (with_u, without_u)
            return max(result[0])
            
        adj = [[] for _ in xrange(len(edges))]
        for i, (p, w) in enumerate(edges):
            if i == 0:
                continue
            adj[p].append((i, w))
        return iter_dfs()

    
# Time:  O(n)
# Space: O(n)
# dfs, tree dp
class Solution2(object):
    def maxScore(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def dfs(u):
            if not adj[u]:
                return (0, 0)
            children = [dfs(v) for v, _ in adj[u]]
            without_u = sum(max(with_v, without_v) for with_v, without_v in children)
            with_u = max(without_u-max(with_v, without_v)+(without_v+adj[u][i][1]) for i, (with_v, without_v) in enumerate(children))
            return (with_u, without_u)
            
        adj = [[] for _ in xrange(len(edges))]
        for i, (p, w) in enumerate(edges):
            if i == 0:
                continue
            adj[p].append((i, w))
        return max(dfs(0))
