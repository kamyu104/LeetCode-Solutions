# Time:  O(m * n * k^2)
# Space: O(k^2)

from sortedcontainers import SortedList


# two pointers, sliding window, sorted List
class Solution(object):
    def minAbsDiff(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        result = [[-1]*(len(grid[0])-(k-1)) for _ in xrange(len(grid)-(k-1))]
        sl = SortedList(grid[0+di][0+dj] for di in xrange(k) for dj in xrange(k))
        for i in xrange(len(grid)-(k-1)):
            sl2 = SortedList(sl)
            for j in xrange(len(grid[0])-(k-1)):
                mn = float("inf")
                prev = float("-inf")
                for x in sl2:
                    if prev != float("-inf") and prev != x:
                        mn = min(mn, x-prev)
                    prev = x
                result[i][j] = mn if mn != float("inf") else 0
                if j+1 == len(grid[0])-(k-1):
                    continue
                for di in xrange(k):
                    sl2.remove(grid[i+di][j])
                    sl2.add(grid[i+di][j+k])
            if i+1 == len(grid)-(k-1):
                continue
            for dj in xrange(k):
                sl.remove(grid[i][0+dj])
                sl.add(grid[i+k][0+dj])
        return result


# Time:  O(m * n * k^2 * logk)
# Space: O(k^2)
# brute force, sort
class Solution2(object):
    def minAbsDiff(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        result = [[-1]*(len(grid[0])-(k-1)) for _ in xrange(len(grid)-(k-1))]
        for i in xrange(len(grid)-(k-1)):
            for j in xrange(len(grid[0])-(k-1)):
                vals = sorted({grid[i+di][j+dj] for di in xrange(k) for dj in xrange(k)})
                result[i][j] = min(vals[x+1]-vals[x] for x in xrange(len(vals)-1)) if len(vals) != 1 else 0
        return result
