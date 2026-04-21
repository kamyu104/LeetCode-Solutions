# Time:  O(n * m)
# Space: O(n * m)

# bfs, flood fill
class Solution(object):
    def colorGrid(self, n, m, sources):
        """
        :type n: int
        :type m: int
        :type sources: List[List[int]]
        :rtype: List[List[int]]
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        result = [[0]*m for _ in xrange(n)]
        lookup = [[-1]*m for _ in xrange(n)]
        q = []
        for r, c, color in sources:
            lookup[r][c] = 0
            result[r][c] = color
            q.append((r, c))
        while q:
            new_q = []
            for r, c in q:
                for dr, dc in DIRECTIONS:
                    nr, nc = r+dr, c+dc
                    if not (0 <= nr < n and 0 <= nc < m):
                        continue
                    if lookup[nr][nc] == -1:
                        lookup[nr][nc] = lookup[r][c]+1
                        result[nr][nc] = result[r][c]
                        new_q.append((nr, nc))
                    elif lookup[nr][nc] == lookup[r][c]+1:
                        result[nr][nc] = max(result[nr][nc], result[r][c])
            q = new_q
        return result
