# Time:  O(n + e)
# Space: O(n)

# union find
class Solution(object):
    def numberOfEdgesAdded(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
            def __init__(self, n):
                self.set = range(n)
                self.rank = [0]*n
                self.parity = [0]*n

            def find_set(self, x):
                stk = []
                while self.set[x] != x:  # path compression
                    stk.append(x)
                    x = self.set[x]
                prev = self.parity[x]  # added
                while stk:
                    self.parity[stk[-1]] ^= prev  # added
                    prev = self.parity[stk[-1]]  # added
                    self.set[stk.pop()] = x
                return x

            def union_set(self, x, y, w):
                x0, y0 = x, y
                x, y = self.find_set(x), self.find_set(y)
                if x == y:
                    return self.parity[x0]^w^self.parity[y0] == 0  # modified
                if self.rank[x] > self.rank[y]:  # union by rank
                    x, y = y, x
                elif self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.set[x] = self.set[y]
                self.parity[x] = self.parity[x0]^w^self.parity[y0]  # added
                return True
    
        uf = UnionFind(n)
        return sum(uf.union_set(u, v, w) for u, v, w in edges)
