# Time:  O(n)
# Space: O(n)

class Solution(object):
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        return len(nums) > len(set(nums))

