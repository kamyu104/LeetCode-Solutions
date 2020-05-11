# Time:  O(m * n * k * (m + n))
# Space: O(m * n * k)

class Solution(object):
    def ways(self, pizza, k):
        """
        :type pizza: List[str]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        prefix = [[0]*len(pizza[0]) for _ in xrange(len(pizza))]
        for j in reversed(xrange(len(pizza[0]))):
            accu = 0
            for i in reversed(xrange(len(pizza))):
                accu += int(pizza[i][j] == 'A')
                prefix[i][j] = (prefix[i][j+1] if (j+1 < len(pizza[0])) else 0) + accu
        dp = [[[0]*k for _ in xrange(len(pizza[0]))] for _ in xrange(len(pizza))]
        for i in reversed(xrange(len(pizza))):
            for j in reversed(xrange(len(pizza[0]))):
                dp[i][j][0] = 1
                for m in xrange(1, k):
                    for n in xrange(i+1, len(pizza)):
                        if prefix[i][j] == prefix[n][j]:
                            continue
                        if prefix[n][j] == 0:
                            break
                        dp[i][j][m] = (dp[i][j][m] + dp[n][j][m-1]) % MOD
                    for n in xrange(j+1, len(pizza[0])):
                        if prefix[i][j] == prefix[i][n]:
                            continue
                        if prefix[i][n] == 0:
                            break
                        dp[i][j][m] = (dp[i][j][m] + dp[i][n][m-1]) % MOD
        return dp[0][0][k-1]
