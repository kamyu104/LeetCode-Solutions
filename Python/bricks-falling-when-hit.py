# Time:  O(r * c)
# Space: O(r * c)

# We have a grid of 1s and 0s; the 1s in a cell represent bricks.
# A brick will not drop if and only if it is directly connected to the top of the grid,
# or at least one of its (4-way) adjacent bricks will not drop.
#
# We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j),
# the brick (if it exists) on that location will disappear,
# and then some other bricks may drop because of that erasure.
#
# Return an array representing the number of bricks that will drop after each erasure in sequence.
#
# Example 1:
# Input: 
# grid = [[1,0,0,0],[1,1,1,0]]
# hits = [[1,0]]
# Output: [2]
# Explanation: 
# If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
#
# Example 2:
# Input: 
# grid = [[1,0,0,0],[1,1,0,0]]
# hits = [[1,1],[1,0]]
# Output: [0,0]
# Explanation: 
# When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move.
# So each erasure will cause no bricks dropping.
# Note that the erased brick (1, 0) will not be counted as a dropped brick.
#
# Note:
# - The number of rows and columns in the grid will be in the range [1, 200].
# - The number of erasures will not exceed the area of the grid.
# - It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
# - An erasure may refer to a location with no brick - if it does, no bricks drop.

class UnionFind:
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
                if not val: continue
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
