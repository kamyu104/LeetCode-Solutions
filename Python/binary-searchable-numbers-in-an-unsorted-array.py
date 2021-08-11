# Time:  O(n)
# Space: O(n)
import collections


class Solution(object):
    def binarySearchableNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count_distinct = True
        right = [float("inf")]*(len(nums)+1)
        for i in reversed(xrange(1, len(nums)+1)):
            right[i-1] = min(right[i], nums[i-1])
        result, left = set(), float("-inf")
        for i in xrange(len(nums)):
            if left <= nums[i] <= right[i+1]:
                result.add(nums[i])
            left = max(left, nums[i])
        return len(result) if count_distinct else sum(int(x in result) for x in nums)
