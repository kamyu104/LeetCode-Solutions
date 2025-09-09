# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 0 if all(x == nums[0] for x in nums) else 1
