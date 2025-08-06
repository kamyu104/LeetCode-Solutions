# Time:  O(n)
# Space: O(1)

# two pointers, greedy
class Solution(object):
    def maxSumTrionic(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = float("-inf")
        left = p = q = 0
        prefix = nums[0]
        for right in xrange(1, len(nums)):
            prefix += nums[right]
            if nums[right-1] > nums[right]:
                if right-2 >= 0 and nums[right-2] < nums[right-1]:
                    p = right-1
                    while left < q or (nums[left] < 0 and left+1 < p):
                        prefix -= nums[left]
                        left += 1
            elif nums[right-1] < nums[right]:
                if right-2 >= 0 and nums[right-2] > nums[right-1]:
                    q = right-1
                if left != p:
                    result = max(result, prefix)
            else:
                left = p = q = right
                prefix = nums[right]
        return result
