# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        result = left = 0
        for right in xrange(len(nums)):
            if not minK <= nums[right] <= maxK:
                left = right+1
                continue
            result += right-left+1
        return result
