# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_nums = max(nums)
        if max_nums < 0:
            return max_nums
        global_max, local_max = 0, 0
        for x in nums:
            local_max = max(0, local_max + x)
            global_max = max(global_max, local_max)
        return global_max
