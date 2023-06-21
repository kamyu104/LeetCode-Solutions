# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def findValueOfPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return min(nums[i+1]-nums[i] for i in xrange(len(nums)-1))
