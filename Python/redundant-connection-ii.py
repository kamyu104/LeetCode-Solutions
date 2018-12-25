# Time:  O(nlog*n) ~= O(n), n is the length of the positions
# Space: O(n)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root or \
           y != y_root:  # already has a father
            return False
        self.set[y_root] = x_root
        return True


class Solution(object):
    def findRedundantDirectedConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        cand1, cand2 = None, None
        parents = {}
        for edge in edges:
            if edge[1] not in parents:
                parents[edge[1]] = edge[0]
            else:
                cand1 = [parents[edge[1]], edge[1]]
                cand2 = edge

        union_find = UnionFind(len(edges)+1)
        for edge in edges:
            if edge == cand2:
                continue
            if not union_find.union_set(*edge):
                return cand1 if cand2 else edge
        return cand2


