# Time:  O(d * n^2)
# Space: O(d * n)

class Solution(object):
    def minDifficulty(self, jobDifficulty, d):
        """
        :type jobDifficulty: List[int]
        :type d: int
        :rtype: int
        """
        if len(jobDifficulty) < d:
            return -1;
        
        dp = [[float("inf")]*len(jobDifficulty) for _ in xrange(d)]
        dp[0][0] = jobDifficulty[0]
        for i in xrange(1, len(jobDifficulty)):
            dp[0][i] = max(dp[0][i-1], jobDifficulty[i])
        for i in xrange(1, d):
            for j in xrange(i, len(jobDifficulty)):
                curr_max = jobDifficulty[j]
                for k in reversed(xrange(i, j+1)):
                    curr_max = max(curr_max, jobDifficulty[k])
                    dp[i][j] = min(dp[i][j], dp[i-1][k-1] + curr_max)
        return dp[d-1][len(jobDifficulty)-1]
