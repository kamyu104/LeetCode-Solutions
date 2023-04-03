# Time:  O(n * alpha(n)) = O(n)
# Space: O(n)

class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.rank = [0]*n
        self.right = range(n)  # added

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
        self.right[y] = max(self.right[x], self.right[y])  # added
        return True

    def right_set(self, x):  # added
        return self.right[self.find_set(x)]


# bfs, union find
class Solution(object):
    def minReverseOperations(self, n, p, banned, k):
        """
        :type n: int
        :type p: int
        :type banned: List[int]
        :type k: int
        :rtype: List[int]
        """
        lookup = [False]*n
        for i in banned:
            lookup[i] = True
        d = 0
        result = [-1]*n
        result[p] = d
        uf = UnionFind(n+2)
        uf.union_set(p, p+2)
        q = [p]
        d += 1
        while q:
            new_q = []
            for p in q:
                left, right = 2*max(p-(k-1), 0)+(k-1)-p, 2*min(p+(k-1), n-1)-(k-1)-p
                p = uf.right_set(left)
                while p <= right:
                    if not lookup[p]:
                        result[p] = d
                        new_q.append(p)
                    uf.union_set(p, p+2)
                    p = uf.right_set(p)
            q = new_q
            d += 1
        return result
