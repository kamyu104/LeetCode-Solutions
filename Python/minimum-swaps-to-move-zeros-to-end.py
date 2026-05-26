# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minimumSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums[i] != 0 for i in xrange(len(nums)-nums.count(0), len(nums)))
