# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        target = sum(nums)-x
        result = -1
        curr = left = 0
        for right in xrange(len(nums)):
            curr += nums[right]
            while left < len(nums) and curr > target:
                curr -= nums[left]
                left += 1
            if curr == target:
                result = max(result, right-left+1)
        return len(nums)-result if result != -1 else -1
