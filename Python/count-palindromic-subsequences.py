# Time:  O(10^(l/2) * n), l = 5
# Space: O(10^(l/2) * n)

# freq table, prefix sum
class Solution(object):
    def countPalindromes(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9+7
        cnt = [0]*10
        left = [[[0]*10 for _ in xrange(10)] for _ in xrange(len(s)+1)]
        for k in xrange(len(s)):
            left[k+1] = [[left[k][i][j] for j in xrange(10)] for i in xrange(10)]
            for i in xrange(10):
                left[k+1][int(s[k])][i] += cnt[i]
            cnt[int(s[k])] += 1
        cnt = [0]*10
        right = [[0]*10 for _ in xrange(10)]
        result = 0
        for k in reversed(xrange(len(s))):
            for i in xrange(10):
                for j in xrange(10):
                    result = (result+left[k][i][j]*right[i][j])%MOD
            for i in xrange(10):
                right[int(s[k])][i] += cnt[i]
            cnt[int(s[k])] += 1
        return result
                    

# Time:  O(10^(l/2) * n * l), l = 5
# Space: O(l)
# dp
class Solution2(object):
    def countPalindromes(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9+7
        result = 0
        for i in xrange(10):
            for j in xrange(10):
                pattern = "%s%s*%s%s" % (i, j, j, i)
                dp = [0]*(5+1)
                dp[0] = 1
                for k in xrange(len(s)):
                    for l in reversed(xrange(5)):
                        if pattern[l] == '*' or pattern[l] == s[k]:
                            dp[l+1] = (dp[l+1]+dp[l])%MOD
                result = (result+dp[5])%MOD
        return result
