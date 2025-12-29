# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def maximumScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, prefix = float("-inf"), sum(nums)
        suffix = float("inf")
        for i in reversed(xrange(len(nums)-1)):
            prefix -= nums[i+1]
            suffix = min(suffix, nums[i+1])
            result = max(result, prefix-suffix)
        return result
