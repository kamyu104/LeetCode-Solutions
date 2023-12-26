# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def numberGame(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        for i in xrange(0, len(nums), 2):
            nums[i], nums[i+1] = nums[i+1], nums[i]
        return nums
