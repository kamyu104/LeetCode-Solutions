# Time:  O(n^2)
# Space: O(n)

# iterative dfs
class Solution(object):
    def canReachCorner(self, X, Y, circles):
        """
        :type X: int
        :type Y: int
        :type circles: List[List[int]]
        :rtype: bool
        """
        def check(x1, y1, r1, x2, y2, r2):
            return (x1-x2)**2+(y1-y2)**2 <= (r1+r2)**2

        def iter_dfs():
            lookup = [False]*len(circles)
            stk = []
            dst = [False]*len(circles)
            for u in xrange(len(circles)):
                x, y, r = circles[u]
                if x-r <= 0 or y+r >= Y:
                    lookup[u] = True
                    stk.append(u)
                if x+r >= X or y-r <= 0:
                    dst[u] = True
            while stk:
                u = stk.pop()
                if dst[u]:
                    return True
                x1, y1, r1 = circles[u]
                for v in xrange(len(circles)):
                    x2, y2, r2 = circles[v]
                    if lookup[v] or not check(x1, y1, r1, x2, y2, r2):
                        continue
                    lookup[v] = True
                    stk.append(v)
            return False

        return not iter_dfs()


# Time:  O(n^2)
# Space: O(n)
# bfs
class Solution2(object):
    def canReachCorner(self, X, Y, circles):
        """
        :type X: int
        :type Y: int
        :type circles: List[List[int]]
        :rtype: bool
        """
        def check(x1, y1, r1, x2, y2, r2):
            return (x1-x2)**2+(y1-y2)**2 <= (r1+r2)**2

        def bfs():
            lookup = [False]*len(circles)
            q = []
            dst = [False]*len(circles)
            for u in xrange(len(circles)):
                x, y, r = circles[u]
                if x-r <= 0 or y+r >= Y:
                    lookup[u] = True
                    q.append(u)
                if x+r >= X or y-r <= 0:
                    dst[u] = True
            while q:
                new_q = []
                for u in q:
                    if dst[u]:
                        return True
                    x1, y1, r1 = circles[u]
                    for v in xrange(len(circles)):
                        x2, y2, r2 = circles[v]
                        if lookup[v] or not check(x1, y1, r1, x2, y2, r2):
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
            return False

        return not bfs()


# Time:  O(n^2)
# Space: O(n^2)
# iterative dfs
class Solution3(object):
    def canReachCorner(self, X, Y, circles):
        """
        :type X: int
        :type Y: int
        :type circles: List[List[int]]
        :rtype: bool
        """
        def check(x1, y1, r1, x2, y2, r2):
            return (x1-x2)**2+(y1-y2)**2 <= (r1+r2)**2

        def iter_dfs(src, dst):
            lookup = [False]*len(adj)
            lookup[src] = True
            stk = [src]
            while stk:
                u = stk.pop()
                if u == dst:
                    return True
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    lookup[v] = True
                    stk.append(v)
            return False

        adj = [[] for _ in xrange(len(circles)+2)]
        for u in xrange(len(circles)):
            x1, y1, r1 = circles[u]
            if x1-r1 <= 0 or y1+r1 >= Y:
                adj[u].append(len(circles))
                adj[len(circles)].append(u)
            if x1+r1 >= X or y1-r1 <= 0:
                adj[u].append(len(circles)+1)
                adj[len(circles)+1].append(u)
            for v in xrange(u):
                x2, y2, r2 = circles[v]
                if not check(x1, y1, r1, x2, y2, r2):
                    continue
                adj[u].append(v)
                adj[v].append(u)
        return not iter_dfs(len(circles), len(circles)+1)


# Time:  O(n^2)
# Space: O(n^2)
# bfs
class Solution4(object):
    def canReachCorner(self, X, Y, circles):
        """
        :type X: int
        :type Y: int
        :type circles: List[List[int]]
        :rtype: bool
        """
        def check(x1, y1, r1, x2, y2, r2):
            return (x1-x2)**2+(y1-y2)**2 <= (r1+r2)**2

        def bfs(src, dst):
            lookup = [False]*len(adj)
            lookup[src] = True
            q = [src]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
            return lookup[dst]

        adj = [[] for _ in xrange(len(circles)+2)]
        for u in xrange(len(circles)):
            x1, y1, r1 = circles[u]
            if x1-r1 <= 0 or y1+r1 >= Y:
                adj[u].append(len(circles))
                adj[len(circles)].append(u)
            if x1+r1 >= X or y1-r1 <= 0:
                adj[u].append(len(circles)+1)
                adj[len(circles)+1].append(u)
            for v in xrange(u):
                x2, y2, r2 = circles[v]
                if not check(x1, y1, r1, x2, y2, r2):
                    continue
                adj[u].append(v)
                adj[v].append(u)
        return not bfs(len(circles), len(circles)+1)


# Time:  O(n^2)
# Space: O(n)
# union find
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


class Solution5(object):
    def canReachCorner(self, X, Y, circles):
        """
        :type X: int
        :type Y: int
        :type circles: List[List[int]]
        :rtype: bool
        """
        def check(x1, y1, r1, x2, y2, r2):
            return (x1-x2)**2+(y1-y2)**2 <= (r1+r2)**2

        uf = UnionFind(len(circles)+2)
        for u in xrange(len(circles)):
            x1, y1, r1 = circles[u]
            if x1-r1 <= 0 or y1+r1 >= Y:
                uf.union_set(u, len(circles))
            if x1+r1 >= X or y1-r1 <= 0:
                uf.union_set(u, len(circles)+1)
            for v in xrange(u):
                x2, y2, r2 = circles[v]
                if not check(x1, y1, r1, x2, y2, r2):
                    continue
                uf.union_set(u, v)
        return uf.find_set(len(circles)) != uf.find_set(len(circles)+1)
