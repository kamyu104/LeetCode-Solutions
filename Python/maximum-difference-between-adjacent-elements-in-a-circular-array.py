# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def maxAdjacentDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(abs(nums[i]-nums[i-1]) for i in xrange(len(nums)))
