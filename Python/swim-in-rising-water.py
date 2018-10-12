# Time:  O(n^2)
# Space: O(n^2)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[min(x_root, y_root)] = max(x_root, y_root)
        return True


class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        positions = [None] * (n**2)
        for i in xrange(n):
            for j in xrange(n):
                positions[grid[i][j]] = (i, j)
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

        union_find = UnionFind(n**2)
        for elevation in xrange(n**2):
            i, j = positions[elevation]
            for direction in directions:
                x, y = i+direction[0], j+direction[1]
                if 0 <= x < n and 0 <= y < n and grid[x][y] <= elevation:
                    union_find.union_set(i*n+j, x*n+y)
                    if union_find.find_set(0) == union_find.find_set(n**2-1):
                        return elevation
        return n**2-1


