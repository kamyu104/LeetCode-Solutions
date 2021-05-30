# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return max(nums[i]+nums[-1-i] for i in xrange(len(nums)//2))
