
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
        result, left = set(), float("-inf")
        for i in xrange(len(nums)):
            if left <= nums[i] <= right[i+1]:
                result.add(nums[i])
            left = max(left, nums[i])
        return len(result)
