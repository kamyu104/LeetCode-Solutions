# Time:  O(n * m * t)
# Space: O(n * m)

# dp, prefix sum
class Solution(object):
    def interleaveCharacters(self, word1, word2, target):
        """
        :type word1: str
        :type word2: str
        :type target: str
        :rtype: int
        """
        MOD = 10**9+7
        dp = [[0]*(len(word2)+1) for _ in xrange(len(word1)+1)]
        dp[0][0] = 1
        for c in target:
            new_dp = [[0]*(len(word2)+1) for _ in xrange(len(word1)+1)]
            col = [0]*(len(word2)+1)
            for i in xrange(len(word1)+1):
                row = 0
                for j in xrange(len(word2)+1):
                    row = (row+dp[i][j])%MOD
                    if j < len(word2) and word2[j] == c:
                        new_dp[i][j+1] = (new_dp[i][j+1]+row)%MOD
                    col[j] = (col[j] + dp[i][j]) % MOD
                    if i < len(word1) and word1[i] == c:
                        new_dp[i+1][j] = (new_dp[i+1][j]+col[j])%MOD
            dp = new_dp
        result = 0
        for i in xrange(1, len(word1)+1):
            for j in xrange(1, len(word2)+1):
                result = (result+dp[i][j])%MOD
        return result
