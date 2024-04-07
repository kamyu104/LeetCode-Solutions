# Time:  O(n + e + q)
# Space: O(n)

# union find
class Solution(object):
    def minimumCost(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
            def __init__(self, n):
                self.set = list(range(n))
                self.rank = [0]*n
                self.w = [-1]*n  # added

            def find_set(self, x):
                stk = []
                while self.set[x] != x:  # path compression
                    stk.append(x)
                    x = self.set[x]
                while stk:
                    self.set[stk.pop()] = x
                return x

            def union_set(self, x, y, w):  # modified
                x, y = self.find_set(x), self.find_set(y)
                if x == y:
                    self.w[x] &= w  # added
                    return False
                if self.rank[x] > self.rank[y]:  # union by rank
                    x, y = y, x
                self.set[x] = self.set[y]
                if self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.w[y] &= self.w[x]&w  # added
                return True
            
            def cost(self, x):  # added
                return self.w[self.find_set(x)]

        uf = UnionFind(n)
        for u, v, w in edges:
            uf.union_set(u, v, w)
        result = [-1]*(len(query))
        for i, (s, t) in enumerate(query):
            if uf.find_set(s) != uf.find_set(t):
                continue
            result[i] = uf.cost(s) if s != t else 0
        return result
