# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(max(nums[i]-nums[i+1], 0) for i in xrange(len(nums)-1))
