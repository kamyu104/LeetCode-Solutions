# Time:  O(m * n * alpha(m + n)) = O(m + n)
# Space: O(m * n)

# bfs, union find
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


class Solution(object):
    def minimumVisitedCells(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        uf1 = [UnionFind(n+1) for _ in xrange(m)]
        uf2 = [UnionFind(m+1) for _ in xrange(n)]
        d, i, j = 1, 0, 0
        q = [(i, j)]
        uf1[i].union_set(j, j+1)
        uf2[j].union_set(i, i+1)
        while q:
            new_q = []
            for i, j in q:
                if (i, j) == (m-1, n-1):
                    return d
                while uf1[i].right_set(j) <= min(j+grid[i][j], n-1):
                    k = uf1[i].right_set(j)
                    new_q.append((i, k))
                    uf2[k].union_set(i, i+1)
                    uf1[i].union_set(k, k+1)
                while uf2[j].right_set(i) <= min(i+grid[i][j], m-1):
                    k = uf2[j].right_set(i)
                    new_q.append((k, j))
                    uf1[k].union_set(j, j+1)
                    uf2[j].union_set(k, k+1)
            q = new_q
            d += 1
        return -1


# Time:  O(m * n * log(m + n))
# Space: O(m * n)
from sortedcontainers import SortedList


# bfs, sorted list
class Solution2_TLE(object):
    def minimumVisitedCells(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        sl1 = [SortedList(xrange(n)) for _ in xrange(m)]
        sl2 = [SortedList(xrange(m)) for _ in xrange(n)]
        d, i, j = 1, 0, 0
        q = [(i, j)]
        while q:
            new_q = []
            for i, j in q:
                if (i, j) == (m-1, n-1):
                    return d
                for k in list(sl1[i].irange(j+1, min(j+grid[i][j], n-1))):
                    new_q.append((i, k))
                    sl2[k].remove(i)
                    sl1[i].remove(k)
                for k in list(sl2[j].irange(i+1, min(i+grid[i][j], m-1))):
                    new_q.append((k, j))
                    sl1[k].remove(j)
                    sl2[j].remove(k)
            q = new_q
            d += 1
        return -1
