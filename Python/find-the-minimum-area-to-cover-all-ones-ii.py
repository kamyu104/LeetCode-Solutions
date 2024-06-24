# Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
# Space: O(1)

# brute force
class Solution(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def minimumArea(min_i, max_i, min_j, max_j):
            min_r, max_r, min_c, max_c = len(grid), -1, len(grid[0]), -1
            for i in xrange(min_i, max_i+1):
                for j in xrange(min_j, max_j+1):
                    if grid[i][j] == 0:
                        continue
                    min_r, max_r, min_c, max_c = min(min_r, i), max(max_r, i), min(min_c, j), max(max_c, j)
            return (max_r-min_r+1)*(max_c-min_c+1)
    
        result = float("inf")
        for i in xrange(len(grid)):
            a = minimumArea(0, i, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(i+1, len(grid)-1, 0, j)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for j in xrange(i+1, len(grid)):
                b = minimumArea(i+1, j, 0, len(grid[0])-1)
                c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(i+1, len(grid)-1, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(0, i, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
        for j in xrange(len(grid[0])):
            a = minimumArea(0, len(grid)-1, 0, j)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, j+1, len(grid[0])-1)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for i in xrange(j+1, len(grid[0])):
                b = minimumArea(0, len(grid)-1, j+1, i)
                c = minimumArea(0, len(grid)-1, i+1, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(0, len(grid)-1, j+1, len(grid[0])-1)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(i+1, len(grid)-1, 0, j)
                result = min(result, a+b+c)
        return result


# Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
# Space: O(n * m)
# brute force
class Solution2(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def minimumArea(min_i, max_i, min_j, max_j):
            min_r, max_r, min_c, max_c = len(grid), -1, len(grid[0]), -1
            for i in xrange(min_i, max_i+1):
                for j in xrange(min_j, max_j+1):
                    if grid[i][j] == 0:
                        continue
                    min_r, max_r, min_c, max_c = min(min_r, i), max(max_r, i), min(min_c, j), max(max_c, j)
            return (max_r-min_r+1)*(max_c-min_c+1)
    
        result = float("inf")
        for _ in xrange(4):
            for i in xrange(len(grid)):
                a = minimumArea(0, i, 0, len(grid[0])-1)
                for j in xrange(len(grid[0])):
                    b = minimumArea(i+1, len(grid)-1, 0, j)
                    c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                    result = min(result, a+b+c)
                for j in xrange(i+1, len(grid)):
                    b = minimumArea(i+1, j, 0, len(grid[0])-1)
                    c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                    result = min(result, a+b+c)
            grid = zip(*grid[::-1])
        return result
