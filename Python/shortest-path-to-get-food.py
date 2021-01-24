# Time:  O(m * n)
# Space: O(m + n)

class Solution(object):
    def getFood(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        q = []
        for r in xrange(len(grid)):
            for c in xrange(len(grid[0])):
                if grid[r][c] == '*':
                    q.append((r, c))
                    break
        
        result = 0
        while q:
            result += 1
            new_q = []
            for r, c in q:
                for dr, dc in directions:
                    nr, nc = r+dr, c+dc
                    if not (0 <= nr < len(grid) and
                            0 <= nc < len(grid[0]) and
                            grid[nr][nc] != 'X'):
                        continue
                    if grid[nr][nc] == '#':
                        return result
                    grid[nr][nc] = 'X'
                    new_q.append((nr, nc))
            q = new_q 
        return -1
