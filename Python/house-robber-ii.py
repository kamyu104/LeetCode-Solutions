# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if len(nums) == 0:
            return 0

        if len(nums) == 1:
            return nums[0]

        return max(self.robRange(nums, 0, len(nums) - 1),\
                   self.robRange(nums, 1, len(nums)))

    def robRange(self, nums, start, end):
        num_i, num_i_1 = nums[start], 0
        for i in xrange(start + 1, end):
            num_i_1, num_i_2 = num_i, num_i_1
            num_i = max(nums[i] + num_i_2, num_i_1)

        return num_i

