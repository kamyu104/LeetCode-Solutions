# Time:  O(n)
# Space: O(1)

class Solution(object):
    def smallestEqual(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return next((i for i, x in enumerate(nums) if i%10 == x), -1)
