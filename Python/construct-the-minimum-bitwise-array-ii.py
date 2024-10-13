# Time:  O(n)
# Space: O(1)

# bit manipulation
class Solution(object):
    def minBitwiseArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [x-(((x+1)&~x)>>1) if x&1 else -1 for x in nums]

