# Time:  O(n^2)
# Space: O(n^2)

class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.rank = [0]*n

    def find_set(self, x):
        stk = []
        while self.set[x] != x:  # path compression
            stk.append(x)
            x = self.set[x]
        while stk:
            self.set[stk.pop()] = x
        return x

    def union_set(self, x, y):
        x, y = self.find_set(x), self.find_set(y)
        if x == y:
            return False
        if self.rank[x] > self.rank[y]:  # union by rank
            x, y = y, x
        self.set[x] = self.set[y]
        if self.rank[x] == self.rank[y]:
            self.rank[y] += 1
        return True


# bfs, bucket sort, union find
class Solution(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def bfs():
            dist = [[0 if grid[r][c] == 1 else -1 for c in xrange(len(grid[0]))] for r in xrange(len(grid))]
            q = [(r, c) for r in xrange(len(grid)) for c in xrange(len(grid[0])) if grid[r][c]]
            d = 0
            while q:
                new_q = []
                for r, c in q:
                    for dr, dc in DIRECTIONS:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(dist) and 0 <= nc < len(dist[0]) and dist[nr][nc] == -1):
                            continue
                        dist[nr][nc] = d+1
                        new_q.append((nr, nc))
                q = new_q
                d += 1
            return dist

        dist = bfs()
        buckets = [[] for _ in xrange((len(grid)-1)+(len(grid[0])-1)+1)]
        for r in xrange(len(grid)):
            for c in xrange(len(grid[0])):
                buckets[dist[r][c]].append((r, c))
        lookup = [[False]*len(grid[0]) for _ in xrange(len(grid))]
        uf = UnionFind(len(grid)*len(grid[0]))
        for d in reversed(xrange(len(buckets))):
            for r, c in buckets[d]:
                for dr, dc in DIRECTIONS:
                    nr, nc = r+dr, c+dc
                    if not (0 <= nr < len(dist) and 0 <= nc < len(dist[0]) and lookup[nr][nc] == True):
                        continue
                    uf.union_set(nr*len(grid[0])+nc, r*len(grid[0])+c)
                lookup[r][c] = True
            if uf.find_set(0*len(grid[0])+0) == uf.find_set((len(grid)-1)*len(grid[0])+(len(grid[0])-1)):
                break
        return d


# Time:  O(n^2 * logn)
# Space: O(n^2)
import heapq


# bfs, dijkstra's algorithm
class Solution2(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def bfs():
            dist = [[0 if grid[r][c] == 1 else -1 for c in xrange(len(grid[0]))] for r in xrange(len(grid))]
            q = [(r, c) for r in xrange(len(grid)) for c in xrange(len(grid[0])) if grid[r][c]]
            d = 0
            while q:
                new_q = []
                for r, c in q:
                    for dr, dc in DIRECTIONS:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(dist) and 0 <= nc < len(dist[0]) and dist[nr][nc] == -1):
                            continue
                        dist[nr][nc] = d+1
                        new_q.append((nr, nc))
                q = new_q
                d += 1
            return dist

        def dijkstra(start, target):
            max_heap = [(-dist[start[0]][start[1]], start)]
            dist[start[0]][start[1]] = -1
            while max_heap:
                curr, u = heapq.heappop(max_heap)
                curr = -curr
                if u == target:
                    return curr
                for dr, dc in DIRECTIONS:
                    nr, nc = u[0]+dr, u[1]+dc
                    if not (0 <= nr < len(dist) and 0 <= nc < len(dist[0]) and dist[nr][nc] != -1):
                        continue
                    heapq.heappush(max_heap, (-min(curr, dist[nr][nc]), (nr, nc)))
                    dist[nr][nc] = -1
            return -1

        dist = bfs()
        return dijkstra(dist, (0, 0), (len(grid)-1, len(grid[0])-1)) 


# Time:  O(n^2 * logn)
# Space: O(n^2)
import heapq


# bfs, binary search
class Solution3(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def bfs():
            dist = [[0 if grid[r][c] == 1 else -1 for c in xrange(len(grid[0]))] for r in xrange(len(grid))]
            q = [(r, c) for r in xrange(len(grid)) for c in xrange(len(grid[0])) if grid[r][c]]
            d = 0
            while q:
                new_q = []
                for r, c in q:
                    for dr, dc in DIRECTIONS:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(dist) and 0 <= nc < len(dist[0]) and dist[nr][nc] == -1):
                            continue
                        dist[nr][nc] = d+1
                        new_q.append((nr, nc))
                q = new_q
                d += 1
            return dist
    
        def check(x):
            lookup = [[False]*len(dist[0]) for _ in xrange(len(dist))]
            q = [(0, 0)]
            lookup[0][0] = True
            while q:
                new_q = []
                for r, c in q:
                    for dr, dc in DIRECTIONS:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(dist) and 0 <= nc < len(dist[0]) and dist[nr][nc] >= x and not lookup[nr][nc]):
                            continue
                        lookup[nr][nc] = True
                        new_q.append((nr, nc))
                q = new_q
            return lookup[-1][-1]
    
        dist = bfs()
        left, right = 0, dist[0][0]
        while left <= right:
            mid = left + (right-left)//2
            if not check(mid):
                right = mid-1
            else:
                left = mid+1
        return right
