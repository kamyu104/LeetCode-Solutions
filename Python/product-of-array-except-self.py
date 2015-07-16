# Time:  O(n)
# Space: O(1)
#
# Given an array of n integers where n > 1, nums,
# return an array output such that output[i] is equal to
# the product of all the elements of nums except nums[i].
#
# Solve it without division and in O(n).
#
# For example, given [1,2,3,4], return [24,12,8,6].
#
#
# Follow up:
# Could you solve it with constant space complexity?
# (Note: The output array does not count as extra space
# for the purpose of space complexity analysis.)
#

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        if not nums:
            return []
            
        left_product = [1 for _ in xrange(len(nums))]
        for i in xrange(1, len(nums)):
            left_product[i] = left_product[i - 1] * nums[i - 1]
            
        right_product = 1
        for i in xrange(len(nums) - 2, -1, -1):
            right_product *= nums[i + 1]
            left_product[i] = left_product[i] * right_product

        return left_product
