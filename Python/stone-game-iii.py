# Time:  O(n)
# Space: O(1)

class Solution(object):
    def stoneGameIII(self, stoneValue):
        """
        :type stoneValue: List[int]
        :rtype: str
        """
        dp = [float("-inf")]*3
        dp[len(stoneValue)%3] = 0
        for i in reversed(xrange(len(stoneValue))):
            max_dp, curr = float("-inf"), 0
            for j in xrange(min(3, len(stoneValue)-i)):
                curr += stoneValue[i+j]
                max_dp = max(max_dp, curr-dp[(i+j+1)%3])
            dp[i%3] = max_dp
        return ["Tie", "Alice", "Bob"][cmp(dp[0], 0)]
