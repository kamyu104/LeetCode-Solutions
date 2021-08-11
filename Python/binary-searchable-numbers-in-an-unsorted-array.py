# Time:  O(n)
# Space: O(n)

class Solution(object):
    def binarySearchableNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = [float("-inf")]*(len(nums)+1)
        for i in xrange(len(nums)):
            left[i+1] = max(left[i], nums[i])
        right = [float("inf")]*(len(nums)+1)
        for i in reversed(xrange(1, len(nums)+1)):
            right[i-1] = min(right[i], nums[i-1])
        result = 0
        for i in xrange(len(nums)):
            if left[i] <= nums[i] <= right[i+1]:
                result += 1
        return result
