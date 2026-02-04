# Time:  O(1)
# Space: O(1)

# greedy, game theory
class Solution(object):
    def finalElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(nums[0], nums[-1])
