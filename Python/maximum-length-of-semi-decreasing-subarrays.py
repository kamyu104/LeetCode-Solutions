# Time:  O(n)
# Space: O(n)

# mono stack
class Solution(object):
    def maxSubarrayLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stk = []
        for i in reversed(xrange(len(nums))):
            if not stk or nums[stk[-1]] > nums[i]:
                stk.append(i)
        result = 0
        for i in xrange(len(nums)):
            while stk and nums[stk[-1]] < nums[i]:
                result = max(result, stk.pop()-i+1)
        return result
