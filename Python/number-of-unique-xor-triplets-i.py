# Time:  O(logn)
# Space: O(1)

# bit manipulation, math
class Solution(object):
    def uniqueXorTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 1<<len(nums).bit_length() if len(nums) >= 3 else len(nums)
