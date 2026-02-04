# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def longestAlternating(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = up1 = up0 = down1 = down0 = 1
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                up1, up0, down1, down0 = down1+1, down0+1, down0, 1
            elif nums[i] > nums[i+1]:
                up1, up0, down1, down0 = up0, 1, up1+1, up0+1
            else:
                up1, up0, down1, down0 = up0, 1, down0, 1
            result = max(result, up1, down1)
        return result
