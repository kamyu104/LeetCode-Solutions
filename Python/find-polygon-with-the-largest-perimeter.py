# Time:  O(nlogn)
# Space: O(1)

# sort, prefix sum, greedy
class Solution(object):
    def largestPerimeter(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        prefix = sum(nums)
        for i in reversed(xrange(2, len(nums))):
            prefix -= nums[i]
            if prefix > nums[i]:
                return prefix+nums[i]
        return -1
