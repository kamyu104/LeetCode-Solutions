# Time:  O(e + q)
# Space: O(n)

import collections
import itertools


class UnionFind(object):
    def __init__(self):
        self.set = {}
        self.rank = collections.Counter()

    def find_set(self, x):
        xp, xr = self.set.setdefault(x, (x, 1.0))
        if x != xp:
            pp, pr = self.find_set(xp)  # path compression.
            self.set[x] = (pp, xr*pr)  # x/pp = xr*pr
        return self.set[x]

    def union_set(self, x, y, r):
        (xp, xr), (yp, yr) =  map(self.find_set, (x, y))
        if xp == yp:
            return False
        if self.rank[xp] < self.rank[yp]:  # union by rank
            # to make x/yp = r*yr and merge xp into yp
            # => since x/xp = xr, we can merge with xp/yp = r*yr/xr 
            self.set[xp] = (yp, r*yr/xr)
        elif self.rank[xp] > self.rank[yp]:
            # to make y/xp = 1/r*xr and merge xp into yp
            # => since y/yp = yr, we can merge with yp/xp = 1/r*xr/yr 
            self.set[yp] = (xp, 1.0/r*xr/yr)
        else:
            # to make y/xp = 1/r*xr and merge xp into yp
            # => since y/yp = yr, we can merge with yp/xp = 1/r*xr/yr 
            self.set[yp] = (xp, 1.0/r*xr/yr)
            self.rank[xp] += 1 
        return True

    def query_set(self, x, y):
        if x not in self.set or y not in self.set:
            return -1.0
        (xp, xr), (yp, yr) = map(self.find_set, (x, y))
        return xr/yr if xp == yp else -1.0


# Time:  O(e + q)
# Space: O(n)
import itertools


# union find
class Solution(object):
    def checkContradictions(self, equations, values):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :rtype: bool
        """
        EPS = 1e-5
        uf = UnionFind()
        return any(not uf.union_set(a, b, k) and abs(uf.query_set(a, b)-k) >= EPS for (a, b), k in itertools.izip(equations, values))


# Time:  O(e + q)
# Space: O(n)
import collections
import itertools


# dfs
class Solution2(object):
    def checkContradictions(self, equations, values):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :rtype: bool
        """
        def isclose(a, b, rel_tol=1e-09, abs_tol=0.0):
            return abs(a-b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)

        def iter_dfs(adj, u, lookup):
            stk = [u]
            lookup[u] = 1.0
            while stk:
                u = stk.pop()
                for v, k in adj[u]:
                    if v in lookup:
                        if not isclose(lookup[v], lookup[u]*k):
                            return True
                        continue
                    lookup[v] = lookup[u]*k
                    stk.append(v)
            return False

        adj = collections.defaultdict(set)
        for (a, b), k in itertools.izip(equations, values):
            adj[a].add((b, 1.0/k))
            adj[b].add((a, 1.0*k))
        lookup = {}
        for u in adj.iterkeys():
            if u in lookup:
                continue
            if iter_dfs(adj, u, lookup):
                return True
        return False
