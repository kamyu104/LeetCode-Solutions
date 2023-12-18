# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def divideArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        nums.sort()
        return [nums[i:i+3] for i in xrange(0, len(nums), 3)] if all(nums[i+2]-nums[i] <= k for i in xrange(0, len(nums), 3)) else []
