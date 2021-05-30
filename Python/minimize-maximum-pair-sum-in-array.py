# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return max(nums[i]+nums[-1-i] for i in xrange(len(nums)//2))
