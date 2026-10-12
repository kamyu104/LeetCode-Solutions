# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def resilientSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = left = 0
        for right in xrange(len(nums)):
            if nums[left]%k != nums[right]%k:
                left = right
            if nums[left]*((right-left+1)-1)%k == 0:
                result = max(result, right-left+1)
        return result
