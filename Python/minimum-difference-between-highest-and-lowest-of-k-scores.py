# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def minimumDifference(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        return min(nums[i]-nums[i-k+1] for i in xrange(k-1, len(nums)))
