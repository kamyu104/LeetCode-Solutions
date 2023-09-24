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
        for left in xrange(len(nums)):
            while stk and nums[stk[-1]] < nums[left]:
                result = max(result, stk.pop()-left+1)
        return result


# Time:  O(nlogn)
# Space: O(n)
# sort
class Solution2(object):
    def maxSubarrayLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idxs = range(len(nums))
        idxs.sort(key=lambda x: nums[x], reverse=True)
        result = 0
        for left in xrange(len(nums)):
            while idxs and nums[idxs[-1]] < nums[left]:
                result = max(result, idxs.pop()-left+1)
        return result
