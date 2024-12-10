# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def constructTransformedArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [nums[(i+nums[i])%len(nums)] for i in xrange(len(nums))]
