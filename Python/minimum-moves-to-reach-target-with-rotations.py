# Time:  O(n)
# Space: O(n)

class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        level, q, lookup = 0, [(0, 0, False)], set()
        while q:
            next_q = []
            for r, c, is_vertical in q:
                if (r, c, is_vertical) in lookup:
                    continue
                if (r, c, is_vertical) == (len(grid)-1, len(grid)-2, False):
                    return level
                lookup.add((r, c, is_vertical))
                if not is_vertical:
                    if c+2 != len(grid[0]) and grid[r][c+2] == 0:
                        next_q.append((r, c+1, is_vertical))
                    if r+1 != len(grid) and grid[r+1][c] == 0 and grid[r+1][c+1] == 0:
                        next_q.append((r+1, c, is_vertical))
                        next_q.append((r, c, not is_vertical))
                else:
                    if r+2 != len(grid) and grid[r+2][c] == 0:
                        next_q.append((r+1, c, is_vertical))
                    if c+1 != len(grid) and grid[r][c+1] == 0 and grid[r+1][c+1] == 0:
                        next_q.append((r, c+1, is_vertical))
                        next_q.append((r, c, not is_vertical))
            q = next_q
            level += 1
        return -1
