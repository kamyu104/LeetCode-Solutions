# Time:  O(m * n)
# Space: O(m + n)

class Solution(object):
    # @return an integer
    def uniquePaths(self, m, n):
        if m < n:
            return self.uniquePaths(n, m)
        ways = [1] * n

        for i in xrange(1, m):
            for j in xrange(1, n):
                ways[j] += ways[j - 1]

        return ways[n - 1]

