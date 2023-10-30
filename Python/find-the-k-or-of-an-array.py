# Time:  O(nlogr)
# Space: O(1)

# bit manipulation
class Solution(object):
    def findKOr(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sum(1<<i for i in xrange(max(nums).bit_length()) if sum((x&(1<<i)) != 0 for x in nums) >= k)
