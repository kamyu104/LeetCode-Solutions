# Time:  O(n^2 * k)
# Space: O(n * k)

class Solution(object):
    def getLengthOfOptimalCompression(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        dp = [[len(s)]*(k+1) for _ in xrange(len(s)+1)]
        dp[0][0] = 0
        for i in xrange(1, len(s)+1):
            for j in xrange(k+1):
                if i-1 >= 0 and j-1 >= 0:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1])
                keep = delete = 0
                for m in xrange(i, len(s)+1):
                    if s[i-1] == s[m-1]:
                        keep += 1
                    else:
                        delete += 1
                    if j+delete > k:
                        break
                    length = dp[i-1][j]+(2 if keep >= 2 else 1)
                    cnt = keep
                    while cnt >= 10:
                        length += 1
                        cnt //= 10
                    dp[m][j+delete] = min(dp[m][j+delete], length);
        return dp[len(s)][k]
