# Time:  O(n)
# Space: O(1)

# bit manipulation
class Solution(object):
    def subsequenceSumOr(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = prefix = 0
        for x in nums:
            prefix += x
            result |= x|prefix
        return result
