# Time:  O(n)
# Space: O(1)
#
# Given an array of numbers nums, in which exactly two
# elements appear only once and all the other elements
# appear exactly twice. Find the two elements that appear only once.
#
# For example:
#
# Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
#
# Note:
# The order of the result is not important. So in the
# above example, [5, 3] is also correct.
# Your algorithm should run in linear runtime complexity.
# Could you implement it using only constant space complexity?
#

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def singleNumber(self, nums):
        x_xor_y = 0
        for i in nums:
            x_xor_y ^= i

        bit = x_xor_y & ~(x_xor_y - 1)

        x = 0
        for i in nums:
            if i & bit:
                x ^= i

        return [x, x_xor_y ^ x]
