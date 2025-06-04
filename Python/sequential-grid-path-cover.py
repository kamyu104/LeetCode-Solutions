# Time:  O(m * n * 3^(m * n))
# Space: O(m * n)

# backtracking
class Solution(object):
    def findPath(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def backtracking(i, j, curr):
            v = grid[i][j]
            if v and v != curr:
                return False
            grid[i][j] = -1
            result.append([i, j])
            if len(result) == len(grid)*len(grid[0]):
                return True
            new_curr = curr+1 if v == curr else curr
            for di, dj in DIRECTIONS:
                ni, nj = i+di, j+dj
                if not (0 <= ni < len(grid) and 0 <= nj < len(grid[0]) and grid[ni][nj] != -1):
                    continue
                if backtracking(ni, nj, new_curr):
                    return True
            result.pop()
            grid[i][j] = v
            return False

        result = []
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if backtracking(i, j, 1):
                    return result
        return result
