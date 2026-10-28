# Time:  O(m^2 * n)
# Space: O(m * n)

# simulation
class Solution(object):
    def finalGrid(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: List[List[str]]
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        NEIGHBORS = ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1))
        bombs = [(r, c) for r in xrange(len(grid)) for c in xrange(len(grid[0])) if grid[r][c] == '*']
        for _ in xrange(len(grid)):
            changed = False
            exploded = []
            for r, c in bombs:
                for dr, dc in DIRECTIONS:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == '#':
                        exploded.append((r, c))
                        break
            for r, c in exploded:
                for dr, dc in NEIGHBORS:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == '#':
                        grid[nr][nc] = '-'
                        changed = True
            for c in xrange(len(grid[0])):
                for r in reversed(xrange(len(grid)-1)):
                    if grid[r][c] == '#' and grid[r+1][c] == '-':
                        grid[r][c], grid[r+1][c] = grid[r+1][c], grid[r][c]
                        changed = True
            if not changed:
                break
        return grid
