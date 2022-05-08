# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def countTexts(self, pressedKeys):
        """
        :type pressedKeys: str
        :rtype: int
        """
        MOD = 10**9+7
        dp = [1]*5
        for i in xrange(1, len(pressedKeys)+1):
            dp[i%5] = 0
            for j in reversed(xrange(max(i-(4 if pressedKeys[i-1] in "79" else 3), 0), i)):
                if pressedKeys[j] != pressedKeys[i-1]:
                    break
                dp[i%5] = (dp[i%5]+dp[j%5])%MOD
        return dp[len(pressedKeys)%5]
