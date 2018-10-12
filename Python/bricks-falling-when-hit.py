# Time:  O(r * c)
# Space: O(r * c)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n+1)
        self.size = [1]*(n+1)
        self.size[-1] = 0

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[min(x_root, y_root)] = max(x_root, y_root)
        self.size[max(x_root, y_root)] += self.size[min(x_root, y_root)]
        return True

    def top(self):
        return self.size[self.find_set(len(self.size)-1)]


class Solution(object):
    def hitBricks(self, grid, hits):
        """
        :type grid: List[List[int]]
        :type hits: List[List[int]]
        :rtype: List[int]
        """
        def index(C, r, c):
            return r*C+c

        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        R, C = len(grid), len(grid[0])

        hit_grid = [row[:] for row in grid]
        for i, j in hits:
            hit_grid[i][j] = 0

        union_find = UnionFind(R*C)
        for r, row in enumerate(hit_grid):
            for c, val in enumerate(row):
                if not val:
                    continue
                if r == 0:
                    union_find.union_set(index(C, r, c), R*C)
                if r and hit_grid[r-1][c]:
                    union_find.union_set(index(C, r, c), index(C, r-1, c))
                if c and hit_grid[r][c-1]:
                    union_find.union_set(index(C, r, c), index(C, r, c-1))

        result = []
        for r, c in reversed(hits):
            prev_roof = union_find.top()
            if grid[r][c] == 0:
                result.append(0)
                continue
            for d in directions:
                nr, nc = (r+d[0], c+d[1])
                if 0 <= nr < R and 0 <= nc < C and hit_grid[nr][nc]:
                    union_find.union_set(index(C, r, c), index(C, nr, nc))
            if r == 0:
                union_find.union_set(index(C, r, c), R*C)
            hit_grid[r][c] = 1
            result.append(max(0, union_find.top()-prev_roof-1))
        return result[::-1]

