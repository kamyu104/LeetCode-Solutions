# Time:  O(n)
# Space: O(n)

# union find
class Solution(object):
    def maxActivated(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
            def __init__(self, n):
                self.set = range(n)
                self.rank = [0]*n
                self.size = [1]*n

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
                elif self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.set[x] = self.set[y]
                self.size[y] += self.size[x]
                return True
            
            def total(self, x):
                return self.size[self.find_set(x)]

        N_DIM, N_ADD = 2, 1
        uf = UnionFind(len(points))
        lookup = [{} for _ in xrange(N_DIM)]
        for i, p in enumerate(points):
            for j in xrange(len(lookup)):
                if p[j] in lookup[j]:
                    uf.union_set(i, lookup[j][p[j]])
                else:
                    lookup[j][p[j]] = i
        top = [0]*min(N_ADD+1, len(points))
        for i in xrange(len(points)):
            if uf.find_set(i) != i:
                continue
            s = uf.total(i)
            for j in xrange(len(top)):
                if s > top[j]:
                    top[j], s = s,top[j]
        return sum(top)+N_ADD
