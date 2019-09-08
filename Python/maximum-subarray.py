# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, curr = float("-inf"), float("-inf")
        for x in nums:
            curr = max(curr+x, x)
            result = max(result, curr)
        return result
