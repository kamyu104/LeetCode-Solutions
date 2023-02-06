# Time:  O(n)
# Space: O(n)

# two pointers, sliding window, dp
class Solution(object):
    def maximizeWin(self, prizePositions, k):
        """
        :type prizePositions: List[int]
        :type k: int
        :rtype: int
        """
        dp = [0]*(len(prizePositions)+1)
        result = left = 0
        for right in xrange(len(prizePositions)):
            while prizePositions[right]-prizePositions[left] > k:
                left += 1
            dp[right+1] = max(dp[right], right-left+1)
            result = max(result, dp[left]+(right-left+1))
        return result
