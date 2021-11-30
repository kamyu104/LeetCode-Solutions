# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getAverages(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        total, l = 0, 2*k+1
        result = [-1]*len(nums)
        for i in xrange(len(nums)):
            total += nums[i]
            if i-l >= 0:
                total -= nums[i-l]
            if i >= l-1:
                result[i-k] = total//l
        return result
