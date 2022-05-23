# Time:  O(n + q)
# Space: O(n)

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
    def __init__(self, children, pairs):
        def preprocess(curr, parent):
            # depth of the node i
            D[curr] = 1 if parent == -1 else D[parent]+1

        def divide(curr, parent):
            stk.append(partial(postprocess, curr))
            for i in reversed(xrange(len(children[curr]))):
                child = children[curr][i]
                if child == parent:
                    continue
                stk.append(partial(conquer, child, curr))
                stk.append(partial(divide, child, curr))
            stk.append(partial(preprocess, curr, parent))

        def conquer(curr, parent):
            uf.union_set(curr, parent)
            uf.update_ancestor_of_set(parent)

        def postprocess(u):
            lookup[u] = True
            for v in pairs[u]:
                if not lookup[v]:
                    continue
                lca[min(u, v), max(u, v)] = uf.find_ancestor_of_set(v)

        N = len(children)
        D, uf, lca = [0]*N, UnionFind(N), {}
        stk, lookup = [], [False]*N
        stk.append(partial(divide, 0, -1))
        while stk:
            stk.pop()()
        self.D, self.lca = D, lca


# Tarjan's Offline LCA Algorithm
class Solution(object):
    def closestNode(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v), adj[v].append(u)
        pairs = collections.defaultdict(set)
        for start, end, node in query:
            pairs[start].add(end), pairs[end].add(start)
            pairs[start].add(node), pairs[node].add(start)
            pairs[end].add(node), pairs[node].add(end)
        tree_infos = TreeInfos(adj, pairs)
        return [max((tree_infos.lca[min(x, y), max(x, y)] for x, y in ((start, end), (start, node), (end, node))), key=lambda x: tree_infos.D[x]) for start, end, node in query]


# Time:  O(nlogn + qlogn)
# Space: O(nlogn)
from functools import partial


# Template:
# https://github.com/kamyu104/GoogleKickStart-2021/blob/main/Round%20H/dependent_events2.py
class TreeInfos2(object):  # Time: O(NlogN), Space: O(NlogN), N is the number of nodes
    def __init__(self, children):  # modified
        def preprocess(curr, parent):
            # depth of the node i
            D[curr] = 1 if parent == -1 else D[parent]+1
            # ancestors of the node i
            if parent != -1:
                P[curr].append(parent)
            i = 0
            while i < len(P[curr]) and i < len(P[P[curr][i]]):
                P[curr].append(P[P[curr][i]][i])
                i += 1
            # the subtree of the node i is represented by traversal index L[i]..R[i]
            C[0] += 1
            L[curr] = C[0]

        def divide(curr, parent):
            stk.append(partial(postprocess, curr))
            for i in reversed(xrange(len(children[curr]))):
                child = children[curr][i]
                if child == parent:
                    continue
                stk.append(partial(divide, child, curr))
            stk.append(partial(preprocess, curr, parent))

        def postprocess(curr):
            R[curr] = C[0]

        N = len(children)
        L, R, D, P, C = [0]*N, [0]*N, [0]*N, [[] for _ in xrange(N)], [-1]
        stk = []
        stk.append(partial(divide, 0, -1))
        while stk:
            stk.pop()()
        assert(C[0] == N-1)
        self.L, self.R, self.D, self.P = L, R, D, P

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
class Solution2(object):
    def closestNode(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v), adj[v].append(u)
        tree_infos = TreeInfos2(adj)
        return [max((tree_infos.lca(x, y) for x, y in ((start, end), (start, node), (end, node))), key=lambda x: tree_infos.D[x]) for start, end, node in query]


# Time:  O(n + q * h)
# Space: O(n)
from functools import partial


# Template:
# https://github.com/kamyu104/GoogleKickStart-2021/blob/main/Round%20H/dependent_events2.py
class TreeInfos3(object):  # Time: O(N), Space: O(N), N is the number of nodes
    def __init__(self, children):  # modified
        def preprocess(curr, parent):
            # depth of the node i
            D[curr] = 1 if parent == -1 else D[parent]+1
            # ancestors of the node i
            P[curr] = parent

        def divide(curr, parent):
            for i in reversed(xrange(len(children[curr]))):
                child = children[curr][i]
                if child == parent:
                    continue
                stk.append(partial(divide, child, curr))
            stk.append(partial(preprocess, curr, parent))

        N = len(children)
        D, P = [0]*N, [0]*N
        stk = []
        stk.append(partial(divide, 0, -1))
        while stk:
            stk.pop()()
        self.D, self.P = D, P

    def lca(self, a, b):  # Time: O(logh)
        while self.D[a] > self.D[b]:
            a = self.P[a]
        while self.D[a] < self.D[b]:
            b = self.P[b]
        while a != b:
            a, b = self.P[a], self.P[b]
        return a


# lca
class Solution3(object):
    def closestNode(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v), adj[v].append(u)
        tree_infos = TreeInfos3(adj)
        return [max((tree_infos.lca(x, y) for x, y in ((start, end), (start, node), (end, node))), key=lambda x: tree_infos.D[x]) for start, end, node in query]


# Time:  O(n^2 + q * n)
# Space: O(n^2)
# bfs
class Solution4(object):
    def closestNode(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        def bfs(adj, root):
            dist = [len(adj)]*len(adj)
            q = [root]
            dist[root] = 0
            d = 0
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if d+1 >= dist[v]:
                            continue
                        dist[v] = d+1
                        new_q.append(v)
                q = new_q
                d += 1
            return dist

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v), adj[v].append(u)
        dist = [bfs(adj, i) for i in xrange(n)]
        result = []
        for start, end, node in query:
            x = end
            while start != end:
                if dist[node][start] < dist[node][x]:
                    x = start
                start = next(u for u in adj[start] if dist[u][end] < dist[start][end])
            result.append(x)
        return result


# Time:  O(n^2 + q * n)
# Space: O(n^2)
# bfs
class Solution5(object):
    def closestNode(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        def bfs(adj, root):
            dist = [len(adj)]*len(adj)
            q = [root]
            dist[root] = 0
            d = 0
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if d+1 >= dist[v]:
                            continue
                        dist[v] = d+1
                        new_q.append(v)
                q = new_q
                d += 1
            return dist

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v), adj[v].append(u)
        dist = [bfs(adj, i) for i in xrange(n)]
        return [max((i for i in xrange(n) if dist[start][node]+dist[node][end]-2*dist[node][i] == dist[start][i]+dist[i][end]), key=lambda x: dist[node][x]) for start, end, node in query]
