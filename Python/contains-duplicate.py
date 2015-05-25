# Time:  O(n)
# Space: O(n)
#
# Given an array of integers, find if the array contains any duplicates.
# Your function should return true if any value appears at least twice in the array, 
# and it should return false if every element is distinct.
#

class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        return len(nums) > len(set(nums))
