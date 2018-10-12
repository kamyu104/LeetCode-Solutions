# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k <= 1: return 0
        result, start, prod = 0, 0, 1
        for i, num in enumerate(nums):
            prod *= num
            while prod >= k:
                prod /= nums[start]
                start += 1
            result += i-start+1
        return result


