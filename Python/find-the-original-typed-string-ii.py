# Time:  O(n + k^2)
# Space: O(n + k)

# dp, prefix sum
class Solution(object):
    def possibleStringCount(self, word, k):
        MOD = 10**9+7
        cnt = [0]
        for i in xrange(len(word)):
            cnt[-1] += 1
            if i+1 == len(word) or word[i+1] != word[i]:
                cnt.append(0)
        cnt.pop()
        result = reduce(lambda accu, x: accu*x%MOD, cnt, 1)
        if k <= len(cnt):
            return result
        dp = [0]*(k-len(cnt))
        dp[0] = 1
        for l in cnt:
            for i in xrange(len(dp)-1):
                dp[i+1] = (dp[i+1]+dp[i])%MOD
            for i in reversed(xrange(l, len(dp))):
                dp[i] = (dp[i]-dp[i-l])%MOD
        return reduce(lambda accu, x: (accu-x)%MOD, dp, result)
