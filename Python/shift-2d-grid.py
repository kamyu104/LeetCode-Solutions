# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def shiftGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        def rotate(grids, k):
            def reverse(grid, start, end):
                while start < end:
                    start_r, start_c = divmod(start, len(grid[0]))
                    end_r, end_c = divmod(end-1, len(grid[0]))
                    grid[start_r][start_c], grid[end_r][end_c] = grid[end_r][end_c], grid[start_r][start_c]
                    start += 1
                    end -= 1

            k %= len(grid)*len(grid[0])
            reverse(grid, 0, len(grid)*len(grid[0]))
            reverse(grid, 0, k)
            reverse(grid, k, len(grid)*len(grid[0]))

        rotate(grid, k)
        return grid
