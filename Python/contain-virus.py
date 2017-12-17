# Time:  O((R * C)^(4/3)), days = O((R * C)^(1/3))
# Space: O(R * C)

# A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
#
# The world is modeled as a 2-D array of cells,
# where 0 represents uninfected cells,
# and 1 represents cells contaminated with the virus.
# A wall (and only one wall) can be installed between any two 4-directionally adjacent cells,
# on the shared boundary.
#
# Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall.
# Resources are limited.
# Each day, you can install walls around only one region -- 
# the affected area (continuous block of infected cells) that
# threatens the most uninfected cells the following night.
# There will never be a tie.
#
# Can you save the day? If so, what is the number of walls required?
# If not, and the world becomes fully infected, return the number of walls used.
#
# Example 1:
# Input: grid = 
# [[0,1,0,0,0,0,0,1],
#  [0,1,0,0,0,0,0,1],
#  [0,0,0,0,0,0,0,1],
#  [0,0,0,0,0,0,0,0]]
# Output: 10
# Explanation:
# There are 2 contaminated regions.
# On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
#
# [[0,1,0,0,0,0,1,1],
#  [0,1,0,0,0,0,1,1],
#  [0,0,0,0,0,0,1,1],
#  [0,0,0,0,0,0,0,1]]
#
# On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
#
# Example 2:
# Input: grid = 
# [[1,1,1],
#  [1,0,1],
#  [1,1,1]]
# Output: 4
# Explanation: Even though there is only one cell saved, there are 4 walls built.
# Notice that walls are only built on the shared boundary of two different cells.
#
# Example 3:
# Input: grid = 
# [[1,1,1,0,0,0,0,0,0],
#  [1,0,1,0,1,1,1,1,1],
#  [1,1,1,0,0,0,0,0,0]]
# Output: 13
#
# Explanation: The region on the left only builds two new walls.
# Note:
# - The number of rows and columns of grid will each be in the range [1, 50].
# - Each grid[i][j] will be either 0 or 1.
# - Throughout the described process, there is always a contiguous viral region
#   that will infect strictly more uncontaminated squares in the next round.

class Solution(object):
    def containVirus(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        def dfs(grid, r, c, lookup, regions, frontiers, perimeters):
            if (r, c) in lookup:
                return
            lookup.add((r, c))
            regions[-1].add((r, c))
            for d in directions:
                nr, nc = r+d[0], c+d[1]
                if not (0 <= nr < len(grid) and \
                        0 <= nc < len(grid[r])):
                    continue
                if grid[nr][nc] == 1:
                    dfs(grid, nr, nc, lookup, regions, frontiers, perimeters)
                elif grid[nr][nc] == 0:
                    frontiers[-1].add((nr, nc))
                    perimeters[-1] += 1

        result = 0
        while True:
            lookup, regions, frontiers, perimeters = set(), [], [], []
            for r, row in enumerate(grid):
                for c, val in enumerate(row):
                    if val == 1 and (r, c) not in lookup:
                        regions.append(set())
                        frontiers.append(set())
                        perimeters.append(0)
                        dfs(grid, r, c, lookup, regions, frontiers, perimeters)

            if not regions: break

            triage_idx = frontiers.index(max(frontiers, key = len))
            for i, region in enumerate(regions):
                if i == triage_idx:
                    result += perimeters[i]
                    for r, c in region:
                        grid[r][c] = -1
                    continue
                for r, c in region:
                    for d in directions:
                        nr, nc = r+d[0], c+d[1]
                        if not (0 <= nr < len(grid) and \
                                0 <= nc < len(grid[r])):
                            continue
                        if grid[nr][nc] == 0:
                            grid[nr][nc] = 1

        return result
