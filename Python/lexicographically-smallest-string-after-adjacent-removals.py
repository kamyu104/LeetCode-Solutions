# Time:  O(n^3)
# Space: O(n^2)

# dp
class Solution(object):
    def lexicographicallySmallestString(self, s):
        """
        :type s: str
        :rtype: str
        """
        dp = [[False]*len(s) for _ in xrange(len(s))]
        for l in xrange(2, len(s)+1, 2):
            for i in xrange(len(s)-(l-1)):
                j = i+(l-1)
                if abs(ord(s[i])-ord(s[j])) in (1, 25) and (j == i+1 or dp[i+1][j-1]):
                    dp[i][j] = True
                    continue
                for k in xrange(i+1, j, 2):
                    if dp[i][k] and dp[k+1][j]:
                        dp[i][j] = True
                        break
        dp2 = [""]*(len(s)+1)
        for i in reversed(xrange(len(s))):
            dp2[i] = s[i]+dp2[i+1]
            for j in xrange(i+1, len(s), 2):
                if dp[i][j]:
                    dp2[i] = min(dp2[i], dp2[j+1])
        return dp2[0]
