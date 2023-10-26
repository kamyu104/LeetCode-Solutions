# Time:  O((m * n) * log(m * n))
# Space: O((m * n) * log(m * n))

# Template: https://github.com/kamyu104/MetaHackerCup-2022/blob/main/Final%20Round/tile_transposing.py3
class PersistentUnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.size = [1]*n
        self.snapshots = []  # added
        self.undos = []  # added

    def find_set(self, x):
        stk = []
        while self.set[x] != x:  # path compression
            stk.append(x)
            x = self.set[x]
        while stk:
            y = stk.pop()
            self.undos.append((~y, self.set[y]))  # added
            self.set[y] = x
        return x

    def union_set(self, x, y):
        x, y = self.find_set(x), self.find_set(y)
        if x == y:
            return False
        if self.size[x] > self.size[y]:  # union by size
            x, y = y, x
        self.undos.append((x, y))  # added
        self.set[x] = self.set[y]
        self.size[y] += self.size[x]
        return True

    def total(self, x):
        return self.size[self.find_set(x)]

    def snapshot(self):  # added
        self.snapshots.append(len(self.undos))

    def rollback(self):  # added
        for _ in xrange(len(self.undos)-self.snapshots.pop()):
            x, y = self.undos.pop()
            if x >= 0:
                self.size[y] -= self.size[x]
                self.set[x] = x
            else:
                self.set[~x] = y


# flood fill, persistent union find
class Solution(object):
    def minDays(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
        def floodfill(grid, i, j, lookup):
            stk = [(i, j)]
            lookup[i][j] = 1
            while stk:
                i, j = stk.pop()
                for di, dj in DIRECTIONS:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < R and 0 <= nj < C and grid[ni][nj] and not lookup[ni][nj]):
                        continue
                    lookup[ni][nj] = 1
                    stk.append((ni, nj))
         
        def count_islands(grid):
            lookup = [[0]*C for _ in xrange(R)]
            island_cnt = 0
            for i in xrange(R):
                for j in xrange(C):
                    if grid[i][j] == 0 or lookup[i][j]:
                        continue
                    island_cnt += 1
                    floodfill(grid, i, j, lookup)
            return island_cnt
    
        def merge(i):
            r, c = divmod(i, C)
            for dr, dc in DIRECTIONS:
                nr, nc = r+dr, c+dc
                ni = nr*C+nc
                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == grid[r][c] and lookup[ni]:
                    uf.union_set(i, ni)

        def check(i):
            r, c = divmod(i, C)
            if grid[r][c] == 0:
                return False
            lookup = set()
            for dr, dc in DIRECTIONS:
                nr, nc = r+dr, c+dc
                if  0 <= nr < R and 0 <= nc < C and grid[nr][nc] == grid[r][c]:
                    lookup.add(uf.find_set(nr*C+nc))
            return len(lookup) != 1

        def dfs(left, right):
            if left == right:
                return check(left)
            mid = left + (right-left)//2
            l1, r1, l2, r2 = left, mid, mid+1, right
            for _ in xrange(2):
                uf.snapshot()
                for i in xrange(l1, r1+1):
                    lookup[i] = True
                    merge(i)
                if dfs(l2, r2):
                    return True
                for i in xrange(l1, r1+1):
                    lookup[i] = False
                uf.rollback()
                l1, r1, l2, r2 = l2, r2, l1, r1
            return False

        R, C = len(grid), len(grid[0])
        if count_islands(grid) != 1:
            return 0
        uf = PersistentUnionFind(R*C)
        lookup = [False]*(R*C)
        return 1 if dfs(0, R*C-1) else 2


# Time:  O(m^2 * n^2)
# Space: O(m * n)
# flood fill
class Solution2(object):
    def minDays(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
        def floodfill(grid, i, j, lookup):
            stk = [(i, j)]
            lookup[i][j] = 1
            while stk:
                i, j = stk.pop()
                for di, dj in DIRECTIONS:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < R and 0 <= nj < C and grid[ni][nj] and not lookup[ni][nj]):
                        continue
                    lookup[ni][nj] = 1
                    stk.append((ni, nj))
         
        def count_islands(grid):
            lookup = [[0]*C for _ in xrange(R)]
            island_cnt = 0
            for i in xrange(R):
                for j in xrange(C):
                    if grid[i][j] == 0 or lookup[i][j]:
                        continue
                    island_cnt += 1
                    floodfill(grid, i, j, lookup)
            return island_cnt

        R, C = len(grid), len(grid[0])
        if count_islands(grid) != 1:
            return 0
        for i in xrange(R):
            for j in xrange(C):
                if grid[i][j] == 0:
                    continue
                grid[i][j] = 0
                island_cnt = count_islands(grid)
                grid[i][j] = 1
                if island_cnt != 1:
                    return 1
        return 2
