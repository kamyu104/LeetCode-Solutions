# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(nums)*len(nums)-sum(nums)
