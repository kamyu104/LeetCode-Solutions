# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, i = 0, 0
        while i+1 < len(nums) and nums[i] < nums[i+1]:
            left += nums[i]
            i += 1
        right, j = 0, len(nums)-1
        while j-1 >= 0 and nums[j] < nums[j-1]:
            right += nums[j]
            j -= 1
        if j-i+1 >= 3:
            return -1
        if j-i+1 == 2:
            return abs((right+nums[j])-(left+nums[i]))
        return min(abs(right-(left+nums[i])), abs((right+nums[j])-left))
