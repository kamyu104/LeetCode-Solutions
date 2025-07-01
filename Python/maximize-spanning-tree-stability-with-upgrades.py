# Time:  O(n + eloge)
# Space: O(n)

# union find, kruskal's algorithm, mst, maximum spanning tree, greedy
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


class Solution(object):
    def maxStability(self, n, edges, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """
        uf = UnionFind(n)
        cnt = 0
        result = float("inf")
        for u, v, s, m in edges:
            if not m:
                continue
            if not uf.union_set(u, v):
                return -1
            cnt += 1
            result = min(result, s)
        edges.sort(key=lambda x: -x[2])
        for u, v, s, m in edges:
            if m:
                continue
            if not uf.union_set(u, v):
                continue
            cnt += 1
            if cnt == (n-1)-k:
                result = min(result, s)
            elif cnt == n-1:
                result = min(result, 2*s)
        return result if cnt == n-1 else -1
