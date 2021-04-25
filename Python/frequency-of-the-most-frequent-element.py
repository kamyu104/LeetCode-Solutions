# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left = 0
        nums.sort()
        for right in xrange(len(nums)):
            k += nums[right]
            if k < nums[right]*(right-left+1):
                k -= nums[left]
                left += 1
        return right-left+1
