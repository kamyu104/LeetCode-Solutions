# Time:  O(n)
# Space: O(1)

# bit manipulation
class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(nums)
        result, l = 1, 0
        for x in nums:
            if x == mx:
                l += 1
                result = max(result, l)
            else:
                l = 0
        return result
