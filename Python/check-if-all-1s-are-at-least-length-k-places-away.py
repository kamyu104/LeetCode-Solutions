# Time:  O(n)
# Space: O(1)

class Solution(object):
    def kLengthApart(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        prev = -k-1
        for i in xrange(len(nums)):
            if not nums[i]:
                continue
            if i-prev <= k:
                return False
            prev = i
        return True
