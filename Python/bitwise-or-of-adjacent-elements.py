# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def orArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [nums[i]|nums[i+1] for i in range(len(nums)-1)]
