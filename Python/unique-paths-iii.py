# Time:  O(m * n * 2^(m * n))
# Space: O(m * n * 2^(m * n))

class Solution(object):
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        def index(grid, r, c):
            return 1 << (r*len(grid[0])+c)

        def dp(grid, src, dst, todo, lookup):
            if src == dst:
                return int(todo == 0)
            key = (src, todo)
            if key in lookup:
                return lookup[key]

            result = 0
            for d in directions:
                r, c = src[0]+d[0], src[1]+d[1]
                if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and \
                   grid[r][c] % 2 == 0 and \
                   todo & index(grid, r, c):
                    result += dp(grid, (r, c), dst, todo ^ index(grid, r, c), lookup)

            lookup[key] = result
            return lookup[key]

        todo = 0
        src, dst = None, None
        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                if val % 2 == 0:
                    todo |= index(grid, r, c)
                if val == 1:
                    src = (r, c)
                elif val == 2:
                    dst = (r, c)
        return dp(grid, src, dst, todo, {})
