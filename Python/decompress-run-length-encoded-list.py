# Time:  O(n)
# Space: O(1)

class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [nums[i+1] for i in xrange(0, len(nums), 2) for _ in xrange(nums[i])]
