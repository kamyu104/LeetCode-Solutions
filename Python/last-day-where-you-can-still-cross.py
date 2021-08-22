# Time:  O(m * n + c *  α(c)) = O(m * n)
# Space: O(m * n)

class UnionFind(object):  # Time: O(n * α(n)), Space: O(n)
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
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        if self.rank[x_root] < self.rank[y_root]:  # union by rank
            self.set[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.set[y_root] = x_root
        else:
            self.set[y_root] = x_root
            self.rank[x_root] += 1
        return True


class Solution(object):
    def latestDayToCross(self, row, col, cells):
        """
        :type row: int
        :type col: int
        :type cells: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def index(n, i, j):
            return i*n+j

        start, end = row*col, row*col+1
        uf = UnionFind(row*col+2)
        lookup = [[False]*col for _ in xrange(row)]
        for i in reversed(xrange(len(cells))):
            r, c = cells[i]
            r, c = r-1, c-1
            for dr, dc in directions:
                nr, nc = r+dr, c+dc
                if not (0 <= nr < row and 0 <= nc < col and lookup[nr][nc]):
                    continue
                uf.union_set(index(col, r, c), index(col, nr, nc))
            if r == 0:
                uf.union_set(start, index(col, r, c))
            if r == row-1:
                uf.union_set(end, index(col, r, c))
            if uf.find_set(start) == uf.find_set(end):
                return i
            lookup[r][c] = True
        return -1
