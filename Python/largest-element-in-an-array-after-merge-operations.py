# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = curr = 0
        for i in reversed(xrange(len(nums))):
            if nums[i] > curr:
                curr = 0
            curr += nums[i]
            result = max(result, curr)
        return result
