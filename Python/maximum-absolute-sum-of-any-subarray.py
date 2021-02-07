# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxAbsoluteSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr = mx = mn = 0
        for num in nums:
            curr += num
            mx = max(mx, curr)
            mn = min(mn, curr)
        return mx-mn
