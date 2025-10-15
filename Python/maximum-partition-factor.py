# Time:  O(n^2 * logn)
# Space: O(n^2)

# greedy, sort, union find with parity
class Solution(object):
    def maxPartitionFactor(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
            def __init__(self, n):
                self.set = range(n)
                self.rank = [0]*n
                self.parity = [0]*n  # added

            def find_set(self, x):
                stk = []
                while self.set[x] != x:  # path compression
                    stk.append(x)
                    x = self.set[x]
                while stk:
                    y = stk.pop()
                    self.parity[y] ^= self.parity[self.set[y]]  # added
                    self.set[y] = x
                return x

            def union_set(self, x, y):
                ox, oy = x, y  # added
                x, y = self.find_set(x), self.find_set(y)
                if x == y:
                    return self.parity[ox] != self.parity[oy]  # modified
                if self.rank[x] > self.rank[y]:  # union by rank
                    x, y = y, x
                    ox, oy = oy, ox  # added
                if self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.set[x] = self.set[y]
                self.parity[x] = self.parity[ox]^self.parity[oy]^1  # added
                return True

        def dist(u, v):
            return abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1])

        sorted_dists = sorted((dist(u, v), u, v) for u in xrange(len(points)) for v in xrange(u+1, len(points)))
        uf = UnionFind(len(points))
        return next((d for d, u, v in sorted_dists if not uf.union_set(u, v)), 0)


# Time:  O(n^2 * logn)
# Space: O(n^2)
# sort, union find
class Solution2(object):
    def maxPartitionFactor(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
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
                    y = stk.pop()
                    self.set[y] = x
                return x

            def union_set(self, x, y):
                x, y = self.find_set(x), self.find_set(y)
                if x == y:
                    return False
                if self.rank[x] > self.rank[y]:  # union by rank
                    x, y = y, x
                if self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.set[x] = self.set[y]
                return True

        def dist(u, v):
            return abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1])

        sorted_dists = sorted((dist(u, v), u, v) for u in xrange(len(points)) for v in xrange(u+1, len(points)))
        uf = UnionFind(len(points))
        lookup = [-1]*len(points)
        for d, u, v in sorted_dists:
            if uf.find_set(u) == uf.find_set(v):
                return d
            if lookup[u] != -1:
                uf.union_set(lookup[u], v)
            else:
                lookup[u] = v
            if lookup[v] != -1:
                uf.union_set(lookup[v], u)
            else:
                lookup[v] = u
        return 0


# Time:  O(n^2 * logn)
# Space: O(n^2)
# binary search, bfs, coordinate compression
class Solution3(object):
    def maxPartitionFactor(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def dist(u, v):
            return abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1])

        def is_bipartite(d):
            def bfs(u):
                if lookup[u] != -1:
                    return True
                lookup[u] = 0
                q = [u]
                while q:
                    new_q = []
                    for u in q:
                        for v in xrange(len(points)):
                            if not (v != u and dist(v, u) < d):
                                continue
                            if lookup[v] != -1:
                                if lookup[v] != lookup[u]^1:
                                    return False
                                continue
                            lookup[v] = lookup[u]^1
                            new_q.append(v)
                    q = new_q
                return True 

            lookup = [-1]*len(points)
            return all(bfs(u) for u in xrange(len(points)))

        sorted_dists = sorted({dist(u, v) for u in xrange(len(points)) for v in xrange(u+1, len(points))}|{INF})
        left, right = 0, len(sorted_dists)-1
        result = binary_search_right(left, right, lambda i: is_bipartite(sorted_dists[i]))
        return sorted_dists[result] if sorted_dists[result] != INF else 0


# Time:  O(n^2 * logr)
# Space: O(n)
# binary search, bfs
class Solution4(object):
    def maxPartitionFactor(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def dist(u, v):
            return abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1])

        def is_bipartite(d):
            def bfs(u):
                if lookup[u] != -1:
                    return True
                lookup[u] = 0
                q = [u]
                while q:
                    new_q = []
                    for u in q:
                        for v in xrange(len(points)):
                            if not (v != u and dist(v, u) < d):
                                continue
                            if lookup[v] != -1:
                                if lookup[v] != lookup[u]^1:
                                    return False
                                continue
                            lookup[v] = lookup[u]^1
                            new_q.append(v)
                    q = new_q
                return True 

            lookup = [-1]*len(points)
            return all(bfs(u) for u in xrange(len(points)))

        mx = max(dist(u, v) for u in xrange(len(points)) for v in xrange(u+1, len(points)))
        left, right = 0, mx+1
        result = binary_search_right(left, right, is_bipartite)
        return result if result != mx+1 else 0
