# Time:  O(n * (alpha(n) + r)) = O(n * r)
# Space: O(n)

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
    def friendRequests(self, n, restrictions, requests):
        """
        :type n: int
        :type restrictions: List[List[int]]
        :type requests: List[List[int]]
        :rtype: List[bool]
        """
        result = []
        uf = UnionFind(n)
        for u, v in requests:
            pu, pv = uf.find_set(u), uf.find_set(v)
            ok = True
            for x, y in restrictions:
                px, py = uf.find_set(x), uf.find_set(y)
                if {px, py} == {pu, pv}:
                    ok = False
                    break
            result.append(ok)
            if ok:
                uf.union_set(u, v) 
        return result
