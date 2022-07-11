# Time:  O(n)
# Space: O(n)

# mono stack
class Solution(object):
    def validSubarraySize(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        stk = [-1]
        for i in xrange(len(nums)+1):
            while stk[-1] != -1 and (i == len(nums) or nums[stk[-1]] >= nums[i]):
                if nums[stk.pop()]*((i-1)-stk[-1]) > threshold:
                    return (i-1)-stk[-1]
            stk.append(i)
        return -1
