# Time:  O(nlogn)
# Space: O(1)

# sort, greedy, two pointers
class Solution(object):
    def maxNumOfMarkedIndices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        result = 0
        right = len(nums)-1
        for left in reversed(xrange(len(nums)//2)):
            if 2*nums[left] <= nums[right]:
                right -= 1
        return ((len(nums)-1)-right)*2
