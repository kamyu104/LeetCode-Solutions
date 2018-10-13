# Time:  O(n^2)
# Space: O(n^2)


class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        def dfs(r, c, index, grid):
            if not (0 <= r < len(grid) and
                    0 <= c < len(grid[0]) and
                    grid[r][c] == 1):
                return 0
            result = 1
            grid[r][c] = index
            for d in directions:
                result += dfs(r+d[0], c+d[1], index, grid)
            return result

        area = {}
        index = 2
        for r in xrange(len(grid)):
            for c in xrange(len(grid[r])):
                if grid[r][c] == 1:
                    area[index] = dfs(r, c, index, grid)
                    index += 1

        result = max(area.values() or [0])
        for r in xrange(len(grid)):
            for c in xrange(len(grid[r])):
                if grid[r][c] == 0:
                    seen = set()
                    for d in directions:
                        nr, nc = r+d[0], c+d[1]
                        if not (0 <= nr < len(grid) and
                                0 <= nc < len(grid[0]) and
                                grid[nr][nc] > 1):
                            continue
                        seen.add(grid[nr][nc])
                    result = max(result, 1 + sum(area[i] for i in seen))
        return result

