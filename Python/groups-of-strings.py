# Time:  O(26 * n)
# Space: O(26 * n)

class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.rank = [0]*n
        self.size = [1]*n
        self.total = n

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
        self.size[y] += self.size[x]
        self.total -= 1
        return True


# bitmasks, union find
class Solution(object):
    def groupStrings(self, words):
        """
        :type words: List[str]
        :rtype: List[int]
        """
        uf = UnionFind(len(words))
        lookup = {}
        for i, x in enumerate(words):
            mask = reduce(lambda x, y: x|(1<<(ord(y)-ord('a'))), x, 0)
            if mask not in lookup:
                lookup[mask] = i
            uf.union_set(i, lookup[mask])
            bit = 1
            while bit <= mask:
                if mask&bit:
                    if mask^bit not in lookup:
                        lookup[mask^bit] = i
                    uf.union_set(i, lookup[mask^bit])
                bit <<= 1
        return [uf.total, max(uf.size)]
