# Time:  O(n)
# Space: O(n)

class Solution(object):
    def binarySearchableNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        right = [float("inf")]*(len(nums)+1)
        for i in reversed(xrange(1, len(nums)+1)):
            right[i-1] = min(right[i], nums[i-1])
        result, left = 0, float("-inf")
        for i in xrange(len(nums)):
            if left <= nums[i] <= right[i+1]:
                result += 1
            left = max(left, nums[i])
        return result
