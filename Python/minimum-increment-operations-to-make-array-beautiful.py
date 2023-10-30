# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def minIncrementOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        W = 3
        dp = [0]*W
        for i, x in enumerate(nums):
            dp[i%W] = min(dp[j%W] for j in xrange(i-W, i))+max(k-x, 0)
        return min(dp)
