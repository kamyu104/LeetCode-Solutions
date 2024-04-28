# Time:  O(n * m)
# Space: O(min(n, m))

# combinatorics
class Solution(object):
    def numberOfRightTriangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def get(i, j):
            return grid[i][j] if n < m else grid[j][i]

        n, m = len(grid), len(grid[0])
        result = 0
        cnt1 = [sum(get(i, j) for j in xrange(max(n, m))) for i in xrange(min(n, m))]
        for j in xrange(max(n, m)):
            cnt2 = sum(get(i, j) for i in xrange(min(n, m)))
            result += sum((cnt1[i]-1)*(cnt2-1) for i in xrange(min(n, m)) if get(i, j))
        return result


# Time:  O(n * m)
# Space: O(n + m)
# combinatorics
class Solution2(object):
    def numberOfRightTriangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m = len(grid), len(grid[0])
        cnt1 = [sum(grid[i][j] for j in xrange(m)) for i in xrange(n)]
        cnt2 = [sum(grid[i][j] for i in xrange(n)) for j in xrange(m)]
        return sum((cnt1[i]-1)*(cnt2[j]-1) for i in xrange(n) for j in xrange(m) if grid[i][j])


# Time:  O(n * m)
# Space: O(min(n, m))
# freq table
class Solution3(object):
    def numberOfRightTriangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def get(i, j):
            return grid[i][j] if n < m else grid[j][i]

        def count(direction):
            result = 0
            cnt = [0]*min(n, m)
            for j in direction(xrange(max(n, m))):
                c = sum(get(i, j) for i in xrange(len(cnt)))
                for i in xrange(len(cnt)):
                    if get(i, j) == 0:
                        continue
                    result += cnt[i]
                    cnt[i] += c-1
            return result
        
        n, m = len(grid), len(grid[0])
        return count(lambda x: x)+count(reversed)
