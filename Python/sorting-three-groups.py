# Time:  O(k * n) = O(n)
# Space: O(k) = O(1)

# dp
class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 3

        dp = [0]*k
        for x in nums:
            dp[x-1] += 1
            for i in xrange(x, len(dp)):
                dp[i] = max(dp[i], dp[i-1])
        return len(nums)-dp[-1]
