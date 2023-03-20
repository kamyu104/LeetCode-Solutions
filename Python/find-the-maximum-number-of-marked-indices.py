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
        left = 0
        for right in xrange((len(nums)+1)//2, len(nums)):
            if nums[right] >= 2*nums[left]:
                left += 1
        return left*2


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
            if nums[right] >= 2*nums[left]:
                left += 1
        return min(left, len(nums)//2)*2
