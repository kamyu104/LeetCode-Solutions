# Time:  O(n^2)
# Space: O(n^2)

# On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
#
# Now rain starts to fall. At time t, the depth of the water everywhere is t.
# You can swim from a square to another 4-directionally adjacent square
# if and only if the elevation of both squares individually are at most t.
# You can swim infinite distance in zero time. Of course,
# you must stay within the boundaries of the grid during your swim.
#
# You start at the top left square (0, 0).
# What is the least time until you can reach the bottom right square (N-1, N-1)?
#
# Example 1:
# Input: [[0,2],[1,3]]
# Output: 3
# Explanation:
# At time 0, you are in grid location (0, 0).
# You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
#
# You cannot reach point (1, 1) until time 3.
# When the depth of water is 3, we can swim anywhere inside the grid.
# Example 2:
#
# Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
# Output: 16
# Explanation:
#  0  1  2  3  4
# 24 23 22 21  5
# 12 13 14 15 16
# 11 17 18 19 20
# 10  9  8  7  6
#
# The final route is marked in bold.
# We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
#
# Note:
# - 2 <= N <= 50.
# - grid[i][j] is a permutation of [0, ..., N*N - 1].

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
        
