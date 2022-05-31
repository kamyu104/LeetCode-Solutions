# Time:  O(n)
# Space: O(n)

# mono stack, dp
class Solution(object):
    def totalSteps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*len(nums)  # dp[i]: number of rounds for nums[i] to remove all the covered elements
        stk = []
        for i in reversed(xrange(len(nums))):
            while stk and nums[stk[-1]] < nums[i]:
                dp[i] = max(dp[i]+1, dp[stk.pop()])
            stk.append(i)
        return max(dp)


# Time:  O(n)
# Space: O(n)
# mono stack, dp
class Solution2(object):
    def totalSteps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*len(nums)  # dp[i]: number of rounds for nums[i] to be removed
        stk = []
        for i in xrange(len(nums)):
            curr = 0
            while stk and nums[stk[-1]] <= nums[i]:
                curr = max(curr, dp[stk.pop()])
            if stk:
                dp[i] = curr+1
            stk.append(i)
        return max(dp)
