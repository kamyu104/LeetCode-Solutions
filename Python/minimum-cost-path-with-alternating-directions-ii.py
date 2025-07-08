# Time:  O(m * n)
# Space: O(1)

# dp
class Solution(object):
    def minCost(self, m, n, waitCost):
        """
        :type m: int
        :type n: int
        :type waitCost: List[List[int]]
        :rtype: int
        """
        waitCost[0][0] = waitCost[m-1][n-1] = 0
        for i in xrange(m):
            for j in xrange(n):
                prev = 0 if (i, j) == (0, 0) else float("inf")
                if i-1 >= 0:
                    prev = min(prev, waitCost[i-1][j])
                if j-1 >= 0:
                    prev = min(prev, waitCost[i][j-1])
                waitCost[i][j] += prev+(i+1)*(j+1)
        return waitCost[m-1][n-1]


# Time:  O(m * n)
# Space: O(n)
# dp
class Solution2(object):
    def minCost(self, m, n, waitCost):
        """
        :type m: int
        :type n: int
        :type waitCost: List[List[int]]
        :rtype: int
        """
        waitCost[0][0] = waitCost[m-1][n-1] = 0
        dp = [0]*n
        for i in xrange(m):
            for j in xrange(n):
                prev = 0 if (i, j) == (0, 0) else float("inf")
                if i-1 >= 0:
                    prev = min(prev, dp[j])
                if j-1 >= 0:
                    prev = min(prev, dp[j-1])
                dp[j] = prev+waitCost[i][j]+(i+1)*(j+1)
        return dp[n-1]
