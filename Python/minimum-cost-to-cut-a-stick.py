# Time:  O(n^3)
# Space: O(n^2)

class Solution(object):
    def minCost(self, n, cuts):
        """
        :type n: int
        :type cuts: List[int]
        :rtype: int
        """
        sorted_cuts = sorted(cuts + [0, n])
        dp = [[0]*len(sorted_cuts) for _ in xrange(len(sorted_cuts))]
        for l in xrange(2, len(sorted_cuts)):
            for i in xrange(len(sorted_cuts)-l):
                dp[i][i+l] = min(dp[i][j]+dp[j][i+l] for j in xrange(i+1, i+l)) + \
                             sorted_cuts[i+l]-sorted_cuts[i]
        return dp[0][len(sorted_cuts)-1]
