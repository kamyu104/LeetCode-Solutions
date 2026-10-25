# Time:  O(m * n)
# Space: O(1)

# simulation
class Solution(object):
    def lastVisitedCell(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: List[int]
        """
        LOOKUP = {'L':(0, -1), 'R':(0, 1), 'U':(-1, 0), 'D':(1, 0)}
        r = c = 0
        while True:
            dr, dc = LOOKUP[grid[r][c]]
            grid[r][c] = '#'
            nr, nc = r+dr, c+dc
            if not (0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] != '#'):
                break
            r, c = nr, nc
        return [r, c]
