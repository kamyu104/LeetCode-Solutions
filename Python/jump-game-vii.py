# Time:  O(n)
# Space: O(n)

# dp with line sweep solution
class Solution(object):
    def canReach(self, s, minJump, maxJump):
        """
        :type s: str
        :type minJump: int
        :type maxJump: int
        :rtype: bool
        """
        dp = [False]*len(s)
        dp[0] = True
        cnt = 0
        for i in xrange(1, len(s)):
            if i >= minJump:
                cnt += dp[i-minJump]
            if i > maxJump:
                cnt -= dp[i-maxJump-1]
            dp[i] = cnt > 0 and s[i] == '0'
        return dp[-1]
