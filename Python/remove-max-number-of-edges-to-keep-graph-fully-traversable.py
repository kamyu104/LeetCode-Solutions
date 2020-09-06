# Time:  O(n + m * α(n)) ~= O(n + m)
# Space: O(n)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.count = n

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[max(x_root, y_root)] = min(x_root, y_root)
        self.count -= 1
        return True


class Solution(object):
    def maxNumEdgesToRemove(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        result = 0
        union_find_a, union_find_b = UnionFind(n), UnionFind(n)
        for t, i, j in edges:
            if t != 3:
                continue
            a = union_find_a.union_set(i-1, j-1)
            b = union_find_b.union_set(i-1, j-1)
            if not a and not b:
                result += 1
        for t, i, j in edges:
            if t == 1:
                if not union_find_a.union_set(i-1, j-1):
                    result += 1
            elif t == 2:
                if not union_find_b.union_set(i-1, j-1):
                    result += 1
        return result if union_find_a.count == union_find_b.count == 1 else -1
