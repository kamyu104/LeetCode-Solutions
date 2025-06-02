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


# iterative dfs, Tarjan's Offline LCA Algorithm, combinatorics
class Solution(object):
    def assignEdgeWeights(self, edges, queries):
        """
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        MOD = 10**9+7
        def iter_dfs():
            lookup = [False]*len(adj)
            lookup2 = [[] for _ in xrange(len(adj))]
            for i, q in enumerate(queries):
                for x in q:
                    lookup2[x-1].append(i)
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
                        if queries[i][0] == queries[i][1]:
                            continue
                        result[i] += dist[u]
                        for x in queries[i]:
                            if lookup[x-1]:
                                result[i] -= 2*dist[ancestor[uf.find_set(x-1)]]
                    lookup[u] = True
                    stk.append((2, (u, 0)))
                elif step == 2:
                    u, i = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    stk.append((2, (u, i+1)))
                    if lookup[v]:
                        continue
                    dist[v] = dist[u]+1
                    stk.append((3, (v, u)))
                    stk.append((1, (v, u)))
                elif step == 3:
                    v, u = args
                    uf.union_set(v, u)
                    ancestor[uf.find_set(u)] = u                    
            return result

        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        result = iter_dfs()
        POW2 = [1]*(len(adj)-1)
        for i in xrange(len(POW2)-1):
            POW2[i+1] = (POW2[i]*2)%MOD
        return [POW2[x-1] if x-1 >= 0 else 0 for x in result]


# Time:  O(n + q)
# Space: O(n + q)
# dfs, Tarjan's Offline LCA Algorithm, combinatorics
class Solution2(object):
    def assignEdgeWeights(self, edges, queries):
        """
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        MOD = 10**9+7
        def dfs(u):
            for i in lookup2[u]:
                if queries[i][0] == queries[i][1]:
                    continue
                result[i] += dist[u]
                for x in queries[i]:
                    if lookup[x-1]:
                        result[i] -= 2*dist[ancestor[uf.find_set(x-1)]]
            lookup[u] = True
            for v in adj[u]:
                if lookup[v]:
                    continue
                dist[v] = dist[u]+1
                dfs(v)
                uf.union_set(v, u)
                ancestor[uf.find_set(u)] = u
            
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        lookup = [False]*len(adj)
        lookup2 = [[] for _ in xrange(len(adj))]
        for i, q in enumerate(queries):
            for x in q:
                lookup2[x-1].append(i)
        uf = UnionFind(len(adj))
        ancestor = range(len(adj))
        dist = [0]*len(adj)
        result = [0]*len(queries)
        dfs(0)
        POW2 = [1]*(len(adj)-1)
        for i in xrange(len(POW2)-1):
            POW2[i+1] = (POW2[i]*2)%MOD
        return [POW2[x-1] if x-1 >= 0 else 0 for x in result]
