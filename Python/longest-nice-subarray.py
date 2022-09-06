# Time:  O(n)
# Space: O(1)

# sliding window, two pointers
class Solution(object):
    def longestNiceSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = left = curr = 0
        for right in xrange(len(nums)):
            while curr&nums[right]:
                curr ^= nums[left]
                left += 1
            curr |= nums[right]
            result = max(result, right-left+1)
        return result
