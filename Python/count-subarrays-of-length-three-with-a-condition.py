# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum((nums[i-1]+nums[i+1])*2 == nums[i] for i in xrange(1, len(nums)-1))
