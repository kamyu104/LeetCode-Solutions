# Time:  O(n * w1 * w2)
# Space: O(w1 * w2)

# dp
class Solution(object):
    def maxWeight(self, weights, w1, w2):
        """
        :type weights: List[int]
        :type w1: int
        :type w2: int
        :rtype: int
        """
        dp = [[False]*(w2+1) for _ in xrange(w1+1)]
        dp[0][0] = True
        for w in weights:
            dp = [[dp[i][j] or (i-w >= 0 and dp[i-w][j]) or (j-w >= 0 and dp[i][j-w]) for j in xrange(w2+1)] for i in xrange(w1+1)]
        result = 0
        for i in xrange(w1+1):
            for j in reversed(xrange(w2+1)):
                if dp[i][j]:
                    result = max(result, i+j)
                    break
        return result
