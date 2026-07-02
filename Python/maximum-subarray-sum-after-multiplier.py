# Time:  O(n)
# Space: O(1)

# dp, kadane's algorithm
class Solution(object):
    def maxSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def sign(x):
            return 1 if x >= 0 else -1

        NEG_ING = float("-inf")
        INIT, MULT, DIV, DONE = range(4)
        result = NEG_ING
        dp = [NEG_ING]*4
        for x in nums:
            dp[:] = [
                max(dp[INIT], 0)+x,
                max(dp[MULT], dp[INIT], 0)+x*k,
                max(dp[DIV], dp[INIT], 0)+sign(x)*(abs(x)//k),
                max(dp[DONE], dp[MULT], dp[DIV], 0)+x,
            ]
            result = max(result, max(dp))
        return result
