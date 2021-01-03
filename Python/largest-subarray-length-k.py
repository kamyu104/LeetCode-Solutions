# Time:  O(n)
# Space: O(1)

class Solution(object):
    def largestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        left, right, l = 0, 1, 0
        while right+k-1 < len(nums) and right+l < len(nums):
            if nums[left+l] == nums[right+l]:
                l += 1
                continue
            if nums[left+l] > nums[right+l]:
                right += l+1
            else:
                left = max(right, min(left+l+1, len(nums)-k))
                right = left+1
            l = 0
        return nums[left:left+k]
