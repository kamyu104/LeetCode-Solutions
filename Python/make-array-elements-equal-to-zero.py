# Time:  O(n)
# Space: O(n)

# prefix sum, CodeChef Starters 146 - Bouncing Ball (https://www.codechef.com/problems/BOUNCE_BALL)
class Solution(object):
    def countValidSelections(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        suffix = [0]*(len(nums)+1)
        for i in reversed(xrange(len(nums))):
            suffix[i] = suffix[i+1]+nums[i]
        return sum(max(2-abs(prefix[i]-suffix[i+1]), 0) for i in xrange(len(nums)) if nums[i] == 0)
