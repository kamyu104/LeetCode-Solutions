# Time:  O(n * op1 * op2)
# Space: O(op1 * op2)

# dp
class Solution(object):
    def minArraySum(self, nums, k, op1, op2):
        """
        :type nums: List[int]
        :type k: int
        :type op1: int
        :type op2: int
        :rtype: int
        """
        dp = [[sum(nums)]*(op2+1) for _ in xrange(op1+1)]
        for x in nums:
            for i in reversed(xrange(op1+1)):
                for j in reversed(xrange(op2+1)):
                    if i-1 >= 0:
                        dp[i][j] = min(dp[i][j], dp[i-1][j]-x+(x+1)//2)
                    if j-1 >= 0:
                        if x-k >= 0:
                            dp[i][j] = min(dp[i][j], dp[i][j-1]-x+(x-k))
                    if i-1 >= 0 and j-1 >= 0:
                        if x-k >= 0:
                            dp[i][j] = min(dp[i][j], dp[i-1][j-1]-x+((x-k)+1)//2)
                        if (x+1)//2-k >= 0:
                            dp[i][j] = min(dp[i][j], dp[i-1][j-1]-x+((x+1)//2-k))
        return dp[op1][op2]
