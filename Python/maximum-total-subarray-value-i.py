# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxTotalValue(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return k*(max(nums)-min(nums))
