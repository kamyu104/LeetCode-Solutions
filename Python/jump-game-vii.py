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


# Time:  O(n)
# Space: O(n)
import collections


# bfs solution
class Solution2(object):
    def canReach(self, s, minJump, maxJump):
        """
        :type s: str
        :type minJump: int
        :type maxJump: int
        :rtype: bool
        """
        q = collections.deque([0])
        reachable = 0
        while q:
            i = q.popleft()
            for j in xrange(max(i+minJump, reachable+1), min(i+maxJump+1, len(s))):
                if s[j] != '0':
                    continue
                q.append(j)
            reachable = i+maxJump
        return i == len(s)-1
