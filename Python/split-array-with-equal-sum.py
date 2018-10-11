# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 7:
            return False

        accumulated_sum = [0] * len(nums)
        accumulated_sum[0] = nums[0]
        for i in xrange(1, len(nums)):
            accumulated_sum[i] = accumulated_sum[i-1] + nums[i]
        for j in xrange(3, len(nums)-3):
            lookup = set()
            for i in xrange(1, j-1):
                if accumulated_sum[i-1] == accumulated_sum[j-1] - accumulated_sum[i]:
                    lookup.add(accumulated_sum[i-1])
            for k in xrange(j+2, len(nums)-1):
                if accumulated_sum[-1] - accumulated_sum[k] == accumulated_sum[k-1] - accumulated_sum[j] and \
                   accumulated_sum[k - 1] - accumulated_sum[j] in lookup:
                    return True
        return False

