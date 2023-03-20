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
        right = len(nums)-1
        for left in reversed(xrange(len(nums)//2)):
            if 2*nums[left] <= nums[right]:
                right -= 1
        return ((len(nums)-1)-right)*2


# Time:  O(nlogn)
# Space: O(1)
# sort, greedy, two pointers
class Solution2(object):
    def maxNumOfMarkedIndices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        left = 0
        for right in xrange(len(nums)):
            if 2*nums[left] <= nums[right]:
                left += 1
        return min(left, len(nums)//2)*2
