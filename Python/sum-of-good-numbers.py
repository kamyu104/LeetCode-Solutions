# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def sumOfGoodNumbers(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sum(nums[i] for i in xrange(len(nums)) if (i-k < 0 or nums[i-k] < nums[i]) and (i+k >= len(nums) or nums[i+k] < nums[i]))
