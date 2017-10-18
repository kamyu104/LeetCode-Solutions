# Time:  ((m * n) * log(m * n))
# Space: (m * n)

class Solution(object):
    def numDistinctIslands2(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        def dfs(i, j, grid, island):
            if not (0 <= i < len(grid) and \
                    0 <= j < len(grid[0]) and \
                    grid[i][j] > 0):
                return False
            grid[i][j] *= -1
            island.append((i, j));
            for d in directions:
                dfs(i+d[0], j+d[1], grid, island)
            return True

        def normalize(island):
            shapes = [[] for _ in xrange(8)]
            for x, y in island:
                rotations_and_reflections = [[ x,  y], [ x, -y], [-x, y], [-x, -y],
                                             [ y,  x], [ y, -x], [-y, x], [-y, -x]]
                for i in xrange(len(rotations_and_reflections)):
                    shapes[i].append(rotations_and_reflections[i])
            for shape in shapes:
                shape.sort()  # Time: O(ilogi), i is the size of the island, the max would be (m * n)
            for shape in shapes:
                origin = list(shape[0])
                for p in shape:
                    p[0] -= origin[0]
                    p[1] -= origin[1]
            return min(shapes)
    
        islands = set()
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                island = []
                if dfs(i, j, grid, island):
                    islands.add(str(normalize(island)))
        return len(islands)
