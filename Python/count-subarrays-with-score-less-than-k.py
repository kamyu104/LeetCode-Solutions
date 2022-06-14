# Time:  O(n)
# Space: O(1)

# sliding window, two pointers
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = total = left = 0
        for right in xrange(len(nums)):
            total += nums[right]
            while total*(right-left+1) >= k:
                total -= nums[left]
                left += 1
            result += right-left+1
        return result
