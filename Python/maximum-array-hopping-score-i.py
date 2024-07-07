# Time:  O(n)
# Space: O(1)

# prefix sum, greedy
class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = mx = 0
        for i in reversed(xrange(1, len(nums))):
            mx = max(mx, nums[i])
            result += mx
        return result


# Time:  O(n^2)
# Space: O(n)
# dp
class Solution2(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*len(nums)
        for i in xrange(1, len(nums)):
            for j in xrange(i):
                dp[i] = max(dp[i], dp[j]+(i-j)*nums[i])
        return dp[-1]
