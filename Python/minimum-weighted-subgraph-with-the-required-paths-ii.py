# Time:  O(n + q)
# Space: O(n + q)

class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.rank = [0]*n

    def find_set(self, x):
        stk = []
        while self.set[x] != x:  # path compression
            stk.append(x)
            x = self.set[x]
        while stk:
            self.set[stk.pop()] = x
        return x

    def union_set(self, x, y):
        x, y = self.find_set(x), self.find_set(y)
        if x == y:
            return False
        if self.rank[x] > self.rank[y]:  # union by rank
            x, y = y, x
        self.set[x] = self.set[y]
        if self.rank[x] == self.rank[y]:
            self.rank[y] += 1
        return True


# iterative dfs, Tarjan's Offline LCA Algorithm
class Solution(object):
    def minimumWeight(self, edges, queries):
        """
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def iter_dfs():
            lookup = [False]*len(adj)
            lookup2 = [[] for _ in xrange(len(adj))]
            for i, q in enumerate(queries):
                for x in q:
                    lookup2[x].append(i)
            uf = UnionFind(len(adj))
            ancestor = range(len(adj))
            dist = [0]*len(adj)
            result = [0]*len(queries)
            stk = [(1, (0,))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u = args[0]
                    for i in lookup2[u]:
                        result[i] += dist[u]
                        for x in queries[i]:
                            if lookup[x]:
                                result[i] -= dist[ancestor[uf.find_set(x)]]
                    lookup[u] = True
                    stk.append((2, (u, 0)))
                elif step == 2:
                    u, i = args
                    if i == len(adj[u]):
                        continue
                    v, w = adj[u][i]
                    stk.append((2, (u, i+1)))
                    if lookup[v]:
                        continue
                    dist[v] = dist[u]+w
                    stk.append((3, (v, u)))
                    stk.append((1, (v, u)))
                elif step == 3:
                    v, u = args
                    uf.union_set(v, u)
                    ancestor[uf.find_set(u)] = u                    
            return result

        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        return iter_dfs()


# Time:  O(n + q)
# Space: O(n + q)
# dfs, Tarjan's Offline LCA Algorithm
class Solution2(object):
    def minimumWeight(self, edges, queries):
        """
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def dfs(u):
            for i in lookup2[u]:
                result[i] += dist[u]
                for x in queries[i]:
                    if lookup[x]:
                        result[i] -= dist[ancestor[uf.find_set(x)]]
            lookup[u] = True
            for v, w in adj[u]:
                if lookup[v]:
                    continue
                dist[v] = dist[u]+w
                dfs(v)
                uf.union_set(v, u)
                ancestor[uf.find_set(u)] = u
            
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        lookup = [False]*len(adj)
        lookup2 = [[] for _ in xrange(len(adj))]
        for i, q in enumerate(queries):
            for x in q:
                lookup2[x].append(i)
        uf = UnionFind(len(adj))
        ancestor = range(len(adj))
        dist = [0]*len(adj)
        result = [0]*len(queries)
        dfs(0)
        return result
