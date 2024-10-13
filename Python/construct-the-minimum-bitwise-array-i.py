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


# Time:  O(n * r)
# Space: O(1)
# brute force
class Solution2(object):
    def minBitwiseArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [next((i for i in xrange(x) if i|(i+1) == x), -1) for x in nums]
