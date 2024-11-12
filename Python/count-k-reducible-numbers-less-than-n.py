# Time:  O(n^2)
# Space: O(n)

# dp
cnt = [0]*2
class Solution(object):
    def countKReducibleNumbers(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        MOD = 10**9+7
        while len(s)-1 >= len(cnt):  # cached
            cnt.append(cnt[popcount(len(cnt))]+1)
        dp = [0]*len(s)
        curr = 0
        for i in xrange(len(s)):
            for j in reversed(range(i)):
                dp[j+1] = (dp[j+1]+dp[j])%MOD
            if s[i] != '1':
                continue
            dp[curr] = (dp[curr]+1)%MOD
            curr += 1
        return reduce(lambda accu, x: (accu+x)%MOD, (dp[i] for i in xrange(1, len(s)) if cnt[i] < k), 0)

