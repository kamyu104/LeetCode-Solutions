# Time:  O(n)
# Space: O(1)

# prefix sum, math
class Solution(object):
    def maximumSumScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = suffix = 0
        result = float("-inf")
        right = len(nums)-1
        for left in xrange(len(nums)):
            prefix += nums[left]
            suffix += nums[right]
            right -= 1
            result = max(result, prefix, suffix)
        return result

    
# Time:  O(n)
# Space: O(1)
# prefix sum
class Solution2(object):
    def maximumSumScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        prefix = 0
        result = float("-inf")
        for x in nums:
            prefix += x
            result = max(result, prefix, total-prefix+x)
        return result
