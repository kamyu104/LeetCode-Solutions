# Time:  O(nlogn)
# Space: O(n)

import collections


class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, vals):
        self.set = range(len(vals))
        self.rank = [0]*len(vals)
        self.cnt = [collections.Counter({v:1}) for v in vals]   # added

    def find_set(self, x):
        stk = []
        while self.set[x] != x:  # path compression
            stk.append(x)
            x = self.set[x]
        while stk:
            self.set[stk.pop()] = x
        return x

    def union_set(self, x, y, v):  # modified
        x, y = self.find_set(x), self.find_set(y)
        if x == y:
            return 0  # modified
        if self.rank[x] > self.rank[y]:  # union by rank
            x, y = y, x
        self.set[x] = self.set[y]
        if self.rank[x] == self.rank[y]:
            self.rank[y] += 1
        cx, cy = self.cnt[x][v], self.cnt[y][v]  # added
        self.cnt[y] = collections.Counter({v:cx+cy})  # added
        return cx*cy  # modified


# tree, sort, union find
class Solution(object):
    def numberOfGoodPaths(self, vals, edges):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        edges.sort(key=lambda x: max(vals[x[0]], vals[x[1]]))
        uf = UnionFind(vals)
        return len(vals)+sum(uf.union_set(i, j, max(vals[i], vals[j])) for i, j in edges)
