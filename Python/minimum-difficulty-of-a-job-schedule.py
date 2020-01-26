# Time:  O(n^2 * d)
# Space: O(n^2)

class Solution(object):
    def minDifficulty(self, jobDifficulty, d):
        """
        :type jobDifficulty: List[int]
        :type d: int
        :rtype: int
        """
        if len(jobDifficulty) < d:
            return -1;

        max_in_range = [[0]*len(jobDifficulty) for _ in xrange(len(jobDifficulty))]
        for i in xrange(len(jobDifficulty)):
            max_in_range[i][i] = jobDifficulty[i]
            for j in xrange(i+1, len(jobDifficulty)):
                max_in_range[i][j] = max(max_in_range[i][j-1], jobDifficulty[j])
        
        dp = [[float("inf")]*d for _ in xrange(len(jobDifficulty))]
        for i in xrange(len(jobDifficulty)):
            dp[i][0] = max_in_range[0][i]
            for j in xrange(1, d):
                for k in reversed(xrange(i)):
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + max_in_range[k+1][i])
        return dp[len(jobDifficulty)-1][d-1]
