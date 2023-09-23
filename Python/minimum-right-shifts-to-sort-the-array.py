# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minimumRightShifts(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = next((i for i in xrange(len(nums)) if not nums[i] < nums[(i+1)%len(nums)]), len(nums))
        j = next((j for j in xrange(i+1, len(nums)) if not nums[j%len(nums)] < nums[(j+1)%len(nums)]), len(nums))
        return len(nums)-(i+1) if j == len(nums) else -1
