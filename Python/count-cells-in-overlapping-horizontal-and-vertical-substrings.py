# Time:  O(n * m)
# Space: O(n * m)

# z-function
class Solution(object):
    def countCells(self, grid, pattern):
        """
        :type grid: List[List[str]]
        :type pattern: str
        :rtype: int
        """
        # Template: https://cp-algorithms.com/string/z-function.html
        def z_function(s):  # Time: O(n), Space: O(n)
            z = [0]*len(s)
            l, r = 0, 0
            for i in xrange(1, len(z)):
                if i <= r:
                    z[i] = min(r-i+1, z[i-l])
                while i+z[i] < len(z) and s[z[i]] == s[i+z[i]]:
                    z[i] += 1
                if i+z[i]-1 > r:
                    l, r = i, i+z[i]-1
            return z

        def check(is_horizontal):
            n, m = len(grid), len(grid[0])
            if not is_horizontal:
                n, m = m, n
            p = len(pattern)
            s = list(pattern)
            if is_horizontal:
                s.extend(grid[i][j] for i in xrange(n) for j in xrange(m))
            else:
                s.extend(grid[j][i] for i in xrange(n) for j in xrange(m))
            lookup = [[False]*m for _ in xrange(n)]
            z = z_function(s)
            curr = 0
            for i in xrange(p, len(s)):
                if z[i] < p:
                    continue
                curr = max(curr, i-p)
                while curr <= (i-p)+p-1:
                    lookup[curr//m][curr%m] = True
                    curr += 1
            return lookup

        lookup1 = check(True)
        lookup2 = check(False)
        return sum(lookup1[i][j] and lookup2[j][i] for i in xrange(len(grid)) for j in xrange(len(grid[0])))
