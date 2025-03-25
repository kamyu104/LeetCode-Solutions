# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums)-min(nums) if len(nums)%2 else sum(nums)-min(nums[i]+nums[i+1] for i in xrange(len(nums)-1))
