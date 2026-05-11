# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def concatWithReverse(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.extend(reversed(nums))
        return nums
