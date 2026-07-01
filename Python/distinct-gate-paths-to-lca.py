# Time:  O(nlog n + qlogn)
# Spece: O(nlogn)

# dfs, binary lifting
class Solution(object):
    def distinctPaths(self, n, parent, gates, queries):
        """
        :type n: int
        :type parent: List[int]
        :type gates: List[List[int]]
        :type queries: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        BB, BR, RB, RR = range(4)
        def ceil_log2(x):
            return (x-1).bit_length()

        def mult(x, y):
            return (
                (x[BB]*y[BB]+x[BR]*y[RB])%MOD,
                (x[BB]*y[BR]+x[BR]*y[RR])%MOD,
                (x[RB]*y[BB]+x[RR]*y[RB])%MOD,
                (x[RB]*y[BR]+x[RR]*y[RR])%MOD,
            )

        def lca(a, b):
            if depth[a] < depth[b]:
                a, b = b, a
            d = depth[a]-depth[b]
            for k in xrange(len(par)):
                if d&(1<<k):
                    a = par[k][a]
            if a == b:
                return a
            for k in reversed(xrange(len(par))):
                if par[k][a] != par[k][b]:
                    a, b = par[k][a], par[k][b]
            return par[0][a]

        def count(u, card, t):
            if u == l:
                return 1
            d = depth[u]-depth[t]
            b, r = 1 if card == 0 else 0, 1 if card == 1 else 0
            for k in xrange(len(par)):
                if not d&(1<<k):
                    continue
                b, r = (b*cnt[k][u][BB]+r*cnt[k][u][RB])%MOD, (b*cnt[k][u][BR]+r*cnt[k][u][RR])%MOD
                u = par[k][u]
            return (b+r)%MOD

        adj = [[] for _ in xrange(n)]
        for u in xrange(n):
            if parent[u] != -1:
                adj[parent[u]].append(u)
        depth = [0]*n
        stk = [0]
        while stk:
            u = stk.pop()
            for v in reversed(adj[u]):
                depth[v] = depth[u]+1
                stk.append(v)
        par = [[0]*n for _ in xrange(ceil_log2(n-1)+1)]
        cnt = [[(0,)*4 for _ in xrange(n)] for _ in xrange(ceil_log2(n-1)+1)]
        for u in xrange(n):
            par[0][u] = parent[u]
            cnt[0][u] = (gates[u][1], gates[u][2], gates[u][2], gates[u][0])
        for k in xrange(1, len(par)):
            for u in xrange(n):
                if par[k-1][u] == -1:
                    continue
                par[k][u] = par[k-1][par[k-1][u]]
                cnt[k][u] = mult(cnt[k-1][u], cnt[k-1][par[k-1][u]])
        result = 0
        for q in queries:
            l = lca(q[0], q[2])
            result ^= (count(q[0], q[1], l)*count(q[2], q[3], l))%MOD
        return result
