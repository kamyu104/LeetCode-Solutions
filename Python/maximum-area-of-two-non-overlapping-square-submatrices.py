# Time:  O(m * n)
# Space: O(n + min(m, n))

# dp
class Solution(object):
    def maxArea(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        l = min(len(mat), len(mat[0]))
        min_r, max_r = [float("inf")]*l, [-1]*l
        min_c, max_c = [float("inf")]*l, [-1]*l
        dp = [0]*len(mat[0])
        for r in xrange(len(mat)):
            new_dp = [0]*len(mat[0])
            for c in xrange(len(mat[0])):
                if not mat[r][c]:
                    continue
                new_dp[c] = min(dp[c-1] if c-1 >= 0 else 0, new_dp[c-1] if c-1 >= 0 else 0, dp[c])+1
                min_r[new_dp[c]-1] = min(min_r[new_dp[c]-1], r)
                max_r[new_dp[c]-1] = max(max_r[new_dp[c]-1], r)
                min_c[new_dp[c]-1] = min(min_c[new_dp[c]-1], c)
                max_c[new_dp[c]-1] = max(max_c[new_dp[c]-1], c)
            dp = new_dp
        return next((i+1 for i in reversed(xrange(l)) if max_r[i]-min_r[i] >= i+1 or max_c[i]-min_c[i] >= i+1), 0)**2
