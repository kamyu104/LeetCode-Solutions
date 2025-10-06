# Time:  O(n)
# Space: O(1)

# bitmasks
class Solution(object):
    def longestSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len(nums)-int(reduce(lambda accu, x: accu^x, nums, 0) == 0) if any(x for x in nums) else 0
