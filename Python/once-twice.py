# Time:  O(n)
# Space: O(1)

# dp, bitmasks
class Solution(object):
    def onceTwice(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dp = [0]*3
        dp[0] = ~0
        for x in nums:
            dp = [(x&dp[i-1])|(~x&dp[i]) for i in xrange(3)]
        dp2 = [0]*3
        dp2[0] = ~0
        for x in nums:
            if ~x&dp[1] or x&dp[2]:
                continue
            dp2 = [(x&dp2[i-1])|(~x&dp2[i]) for i in xrange(3)]
        return [dp2[1], (dp2[1]^dp[1])|dp[2]]
