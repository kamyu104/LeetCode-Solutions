# Time:  O(n)
# Space: O(1)

# prefix sum, greedy
class Solution(object):
    def makeArrayPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MAX_VAL = 10**18
        result = 0
        prev1 = nums[0]+nums[1]
        prev2 = nums[0]
        max_prev3 = 0
        for i in xrange(2, len(nums)):
            prefix = prev1+nums[i]
            if prefix-max_prev3 <= 0:
                prefix = prev1+MAX_VAL
                result += 1
            max_prev3 = max(max_prev3, prev2)
            prev1, prev2 = prefix, prev1
        return result
