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
