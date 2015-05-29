# Time:  O(n)
# Space: O(n)
#
# Given an array of integers and an integer k, return true if 
# and only if there are two distinct indices i and j in the array 
# such that nums[i] = nums[j] and the difference between i and j is at most k.
#

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        lookup = {}
        for i, num in enumerate(nums):
            if num not in lookup:
                lookup[num] = i
            else:
                # It the value occurs before, check the difference.
                if i - lookup[num] <= k:
                    return True
                # Update the index of the value.
                lookup[num] = i
        return False
