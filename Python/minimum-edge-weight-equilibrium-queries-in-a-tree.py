# Time:  O(r * (n + q)), r = max(w for _, _, w in edges)
# Space: O(r * n + q)

import collections
from functools import partial


# Template:
# https://github.com/kamyu104/GoogleKickStart-2021/blob/main/Round%20H/dependent_events3.py
# Tarjan's Offline LCA Algorithm
class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.rank = [0]*n
        self.ancestor = range(n)  # added

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

    def find_ancestor_of_set(self, x):  # added
        return self.ancestor[self.find_set(x)]

    def update_ancestor_of_set(self, x):  # added
        self.ancestor[self.find_set(x)] = x


class TreeInfos(object):  # Time: O(N), Space: O(N + Q), N is the number of nodes
    def __init__(self, adj, pairs):
        def preprocess(u, p, w):  # modified
            # depth of the node i
            D[u] = 1 if p == -1 else D[p]+1
            if w != -1:  # added
                cnt[w] += 1
            CNT[u] = cnt[:]  # added

        def divide(u, p, w):  # modified
            stk.append(partial(postprocess, u, w))  # modified
            for i in reversed(xrange(len(adj[u]))):
                v, nw = adj[u][i]
                if v == p:
                    continue
                stk.append(partial(conquer, v, u))
                stk.append(partial(divide, v, u, nw))  # modified
            stk.append(partial(preprocess, u, p, w))  # modified

        def conquer(u, p):
            uf.union_set(u, p)
            uf.update_ancestor_of_set(p)

        def postprocess(u, w):  # modified
            lookup[u] = True
            for v in pairs[u]:
                if not lookup[v]:
                    continue
                lca[min(u, v), max(u, v)] = uf.find_ancestor_of_set(v)
            if w != -1:  # added
                cnt[w] -= 1

        N = len(adj)
        D, uf, lca = [0]*N, UnionFind(N), {}
        CNT = [[0]*MAX_W for _ in xrange(N)]  # added
        cnt = [0]*MAX_W  # added
        stk, lookup = [], [False]*N
        stk.append(partial(divide, 0, -1, -1))  # modified
        while stk:
            stk.pop()()
        self.D, self.lca = D, lca
        self.CNT = CNT  # added


# Tarjan's Offline LCA Algorithm
MAX_W = 26
class Solution(object):
    def minOperationsQueries(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            w -= 1
            adj[u].append((v, w))
            adj[v].append((u, w))
        pairs = collections.defaultdict(set)
        for a, b in queries:
            pairs[a].add(b), pairs[b].add(a)
        tree_infos = TreeInfos(adj, pairs)
        result = [0]*len(queries)
        for i, (a, b) in enumerate(queries):
            lca = tree_infos.lca[min(a, b), max(a, b)]
            result[i] = (tree_infos.D[a]+tree_infos.D[b]-2*tree_infos.D[lca])-max(tree_infos.CNT[a][w]+tree_infos.CNT[b][w]-2*tree_infos.CNT[lca][w] for w in xrange(MAX_W))
        return result


# Time:  O(r * (n + q) + nlogn + qlogn), r = max(w for _, _, w in edges)
# Space: O(r * n + nlogn)
import collections
from functools import partial


# Template:
# https://github.com/kamyu104/GoogleKickStart-2021/blob/main/Round%20H/dependent_events2.py
class TreeInfos2(object):  # Time: O(NlogN), Space: O(NlogN), N is the number of nodes
    def __init__(self, adj):  # modified
        def preprocess(u, p, w):
            # depth of the node i
            D[u] = 1 if p == -1 else D[p]+1
            # ancestors of the node i
            if p != -1:
                P[u].append(p)
            i = 0
            while i < len(P[u]) and i < len(P[P[u][i]]):
                P[u].append(P[P[u][i]][i])
                i += 1
            # the subtree of the node i is represented by traversal index L[i]..R[i]
            C[0] += 1
            L[u] = C[0]
            if w != -1:  # added
                cnt[w] += 1
            CNT[u] = cnt[:]  # added

        def divide(u, p, w):  # modified
            stk.append(partial(postprocess, u, w))  # modified
            for i in reversed(xrange(len(adj[u]))):
                v, nw = adj[u][i]
                if v == p:
                    continue
                stk.append(partial(divide, v, u, nw))  # modified
            stk.append(partial(preprocess, u, p, w))  # modified

        def postprocess(u, w):  # modified
            R[u] = C[0]
            if w != -1:  # added
                cnt[w] -= 1

        N = len(adj)
        L, R, D, P, C = [0]*N, [0]*N, [0]*N, [[] for _ in xrange(N)], [-1]
        CNT = [[0]*MAX_W for _ in xrange(N)]  # added
        cnt = [0]*MAX_W  # added
        stk = []
        stk.append(partial(divide, 0, -1, -1))  # modified
        while stk:
            stk.pop()()
        assert(C[0] == N-1)
        self.L, self.R, self.D, self.P = L, R, D, P
        self.CNT = CNT  # added

    # Template:
    # https://github.com/kamyu104/FacebookHackerCup-2019/blob/master/Final%20Round/little_boat_on_the_sea.py
    def is_ancestor(self, a, b):  # includes itself
        return self.L[a] <= self.L[b] <= self.R[b] <= self.R[a]

    def lca(self, a, b):
        if self.D[a] > self.D[b]:
            a, b = b, a
        if self.is_ancestor(a, b):
            return a
        for i in reversed(xrange(len(self.P[a]))):  # O(logN)
            if i < len(self.P[a]) and not self.is_ancestor(self.P[a][i], b):
                a = self.P[a][i]
        return self.P[a][0]


# binary lifting (online lca algorithm)
MAX_W = 26
class Solution2(object):
    def minOperationsQueries(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            w -= 1
            adj[u].append((v, w))
            adj[v].append((u, w))
        tree_infos = TreeInfos2(adj)
        result = [0]*len(queries)
        for i, (a, b) in enumerate(queries):
            lca = tree_infos.lca(a, b)
            result[i] = (tree_infos.D[a]+tree_infos.D[b]-2*tree_infos.D[lca])-max(tree_infos.CNT[a][w]+tree_infos.CNT[b][w]-2*tree_infos.CNT[lca][w] for w in xrange(MAX_W))
        return result
