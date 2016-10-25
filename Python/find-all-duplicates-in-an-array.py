# Time:  O(n)
# Space: O(1)

# Given an array of integers, 1 <= a[i] <= n (n = size of array),
# some elements appear twice and others appear once.
# Find all the elements that appear twice in this array.
# Could you do it without extra space and in O(n) runtime?
#
# Example:
# Input
#
# [4,3,2,7,8,2,3,1]
#
# Output
#
# [2,3]

class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        i = 0
        while i < len(nums):
            if nums[i] != nums[nums[i]-1]:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1] 
            else:
                i += 1

        for i in xrange(len(nums)):
            if i != nums[i]-1:
                result.append(nums[i])
        return result
