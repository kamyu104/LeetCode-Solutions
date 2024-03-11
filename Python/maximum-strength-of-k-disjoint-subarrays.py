# Time:  O(k * n)
# Space: O(n)

# dp, greedy, kadane's algorithm
class Solution(object):
    def maximumStrength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [0]*(len(nums)+1)
        for i in xrange(k):
            new_dp = [float("-inf")]*(len(nums)+1)
            for j in xrange(len(nums)):
                new_dp[j+1] = max(new_dp[j], dp[j])+nums[j]*(k-i)*(1 if i%2 == 0 else -1)
            dp = new_dp
        return max(dp)


# Time:  O(k * n)
# Space: O(k * n)
# dp, greedy, kadane's algorithm
class Solution2(object):
    def maximumStrength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [[float("-inf")]*(len(nums)+1) for _ in xrange(k+1)]
        dp[0] = [0]*(len(nums)+1)
        for i in xrange(k):
            for j in xrange(len(nums)):
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j])+nums[j]*(k-i)*(1 if i%2 == 0 else -1)
        return max(dp[-1])
