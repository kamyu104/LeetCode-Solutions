# Time:  O(nlogn)
# Space: O(n)

class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i & -i)
        return ret


# iterative dfs, fenwick tree
class Solution(object):
    def treeQueries(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def iter_dfs():
            L, R, dist, lookup = [0]*n, [0]*n, [0]*n, [0]*n
            cnt = 0
            stk = [(1, (0, -1, 0))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, d = args
                    L[u] = cnt
                    cnt += 1
                    dist[u] = d
                    stk.append((2, (u,)))
                    for v, w in adj[u]:
                        if v == p:
                            continue
                        lookup[v] = w
                        stk.append((1, (v, u, d+w)))
                elif step == 2:
                    u = args[0]
                    R[u] = cnt
            return L, R, dist, lookup

        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            u -= 1
            v -= 1
            adj[u].append((v, w))
            adj[v].append((u, w))
        L, R, dist, lookup = iter_dfs()
        bit = BIT(n)
        result = []
        for q in queries:
            if q[0] == 1:
                _, u, v, w = q
                u -= 1
                v -= 1
                if L[u] > L[v]:
                    u, v = v, u 
                diff = w-lookup[v]
                bit.add(L[v], diff)
                bit.add(R[v], -diff)
                lookup[v] = w
            else:
                _, x = q
                x -= 1
                result.append(dist[x]+bit.query(L[x]))
        return result


# Time:  O(nlogn)
# Space: O(n)
# dfs, fenwick tree
class Solution2(object):
    def treeQueries(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def dfs(u, p, d):
            L[u] = cnt[0]
            cnt[0] += 1
            dist[u] = d
            for v, w in adj[u]:
                if v == p:
                    continue
                lookup[v] = w
                dfs(v, u, d+w)
            R[u] = cnt[0]

        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            u -= 1
            v -= 1
            adj[u].append((v, w))
            adj[v].append((u, w))
        L, R, dist, lookup = [0]*n, [0]*n, [0]*n, [0]*n
        cnt = [0]
        dfs(0, -1, 0)
        bit = BIT(n)
        result = []
        for q in queries:
            if q[0] == 1:
                _, u, v, w = q
                u -= 1
                v -= 1
                if L[u] > L[v]:
                    u, v = v, u 
                diff = w-lookup[v]
                bit.add(L[v], diff)
                bit.add(R[v], -diff)
                lookup[v] = w
            else:
                _, x = q
                x -= 1
                result.append(dist[x]+bit.query(L[x]))
        return result
