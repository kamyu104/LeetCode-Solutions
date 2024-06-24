# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def minimumAverage(self, nums):
        """
        :type nums: List[int]
        :rtype: float
        """
        nums.sort()
        return min((nums[i]+nums[~i])/2.0 for i in xrange(len(nums)//2))
