# Time:  O(t + 26)
# Space: O(26)

# dp
class Solution(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [1]*26
        for i in xrange(26, (ord(max(s))-ord('a')+t)+1):
            dp[i%26] = (dp[(i-26)%26]+dp[((i-26)+1)%26])%MOD
        return reduce(lambda accu, x: (accu+x)%MOD, (dp[((ord(x)-ord('a'))+t)%26] for x in s), 0)
