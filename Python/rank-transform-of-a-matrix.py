# Time:  O(m * n * log(m * n) + m * n * α(m * n)) = O(m * n * log(m * n))
# Space: O(m * n)

import collections


class UnionFind(object):  # Time: O(n * α(n)), Space: O(n)
    def __init__(self, n, cb):
        self.set = range(n)
        self.rank = [0]*n
        self.cb = cb

    def find_set(self, x):
        stk = []
        while self.set[x] != x:  # path compression
            stk.append(x)
            x = self.set[x]
        while stk:
            self.set[stk.pop()] = x
        return x

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        if self.rank[x_root] < self.rank[y_root]:  # union by rank
            self.set[x_root] = y_root
            self.cb(y_root, x_root, y_root)
        elif self.rank[x_root] > self.rank[y_root]:
            self.set[y_root] = x_root
            self.cb(x_root, x_root, y_root)
        else:
            self.set[y_root] = x_root
            self.rank[x_root] += 1
            self.cb(x_root, x_root, y_root)
        return True


class Solution(object):
    def matrixRankTransform(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        def cb(x, y, z):
            new_rank[x] = max(new_rank[y], new_rank[z])

        lookup = collections.defaultdict(list)
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                lookup[matrix[i][j]].append([i, j])
        rank = [0]*(len(matrix)+len(matrix[0]))
        for x in sorted(lookup):
            new_rank = rank[:]
            union_find = UnionFind(len(matrix)+len(matrix[0]), cb)
            for i, j in lookup[x]:
                union_find.union_set(i, j+len(matrix))
            for i, j in lookup[x]:
                matrix[i][j] = rank[i] = rank[j+len(matrix)] = new_rank[union_find.find_set(i)]+1
        return matrix
