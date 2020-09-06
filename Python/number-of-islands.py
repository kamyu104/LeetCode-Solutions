# Time:  O(m * n * α(m * n)) ~= O(m * n)
# Space: O(m * n)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.count = n

    def find_set(self, x):
       if self.set[x] != x:
           self.set[x] = self.find_set(self.set[x])  # path compression.
       return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root != y_root:
            self.set[min(x_root, y_root)] = max(x_root, y_root)
            self.count -= 1


class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def index(n, i, j):
            return i*n + j
    
        if not grid:
            return 0

        zero_count = 0
        union_find = UnionFind(len(grid)*len(grid[0]))
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j] == '1':
                    if i and grid[i-1][j] == '1':
                        union_find.union_set(index(len(grid[0]), i-1, j),
                                             index(len(grid[0]),i, j))
                    if j and grid[i][j-1] == '1':
                        union_find.union_set(index(len(grid[0]), i, j-1),
                                             index(len(grid[0]), i, j))
                else:
                    zero_count += 1        
        return union_find.count-zero_count


# Time:  O(m * n)
# Space: O(m * n)
# dfs solution
class Solution2(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        count = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j] == '0':
                    continue
                grid[i][j] = '0'
                stk = [(i, j)]
                while stk:
                    r, c = stk.pop()
                    for dr, dc in directions:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(grid) and
                                0 <= nc < len(grid[0]) and
                                grid[nr][nc] == '1'):
                            continue
                        grid[nr][nc] ='0'
                        stk.append((nr, nc))
                count += 1
        return count

 
# Time:  O(m * n)
# Space: O(m * n)
# bfs solution
class Solution3(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        count = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j] == '0':
                    continue
                grid[i][j] ='0'
                q = [(i, j)]
                while q:
                    new_q = []
                    for r, c in q:
                        for dr, dc in directions:
                            nr, nc = r+dr, c+dc
                            if not (0 <= nr < len(grid) and
                                    0 <= nc < len(grid[0]) and
                                    grid[nr][nc] == '1'):
                                continue
                            grid[nr][nc] ='0'
                            new_q.append((nr, nc))
                    q = new_q
                count += 1
        return count
