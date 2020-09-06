# Time:  O(m * n * α(n)) ~= O(m * n)
# Space: O(m * n)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.count = n

    def find_set(self, x):
       if self.set[x] != x:
           self.set[x] = self.find_set(self.set[x])  # path compression.
       return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root != y_root:
            self.set[min(x_root, y_root)] = max(x_root, y_root)
            self.count -= 1


class Solution(object):
    def containsCycle(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
        def index(n, i, j):
            return i*n + j
    
        union_find = UnionFind(len(grid)*len(grid[0]))
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if i and j and grid[i][j] == grid[i-1][j] == grid[i][j-1] and \
                   union_find.find_set(index(len(grid[0]), i-1, j)) == \
                   union_find.find_set(index(len(grid[0]), i, j-1)):
                    return True
                if i and grid[i][j] == grid[i-1][j]:
                    union_find.union_set(index(len(grid[0]), i-1, j),
                                         index(len(grid[0]),i, j))
                if j and grid[i][j] == grid[i][j-1]:
                    union_find.union_set(index(len(grid[0]), i, j-1),
                                         index(len(grid[0]), i, j))
        return False


# Time:  O(m * n)
# Space: O(m * n)
class Solution2(object):
    def containsCycle(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if not grid[i][j]:
                    continue
                val = grid[i][j]
                q = [(i, j)]
                while q:
                    new_q = []
                    for r, c in q:
                        if not grid[r][c]:
                            return True
                        grid[r][c] = 0
                        for dr, dc in directions:
                            nr, nc = r+dr, c+dc
                            if not (0 <= nr < len(grid) and
                                    0 <= nc < len(grid[0]) and
                                    grid[nr][nc] == val):
                                continue
                            new_q.append((nr, nc))
                    q = new_q
        return False
