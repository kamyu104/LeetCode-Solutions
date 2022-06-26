# Time:  O(n)
# Space: O(1)

# bit manipulation
class Solution(object):
    def maximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda x, y: x|y, nums)
