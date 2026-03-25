# Time:  O(n)
# Space: O(1)

# combinatorics, two pointers
class Solution(object):
    def validSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result, left, l = 0, -1, 0
        for right in xrange(1, len(nums)-1):
            if not nums[right-1] < nums[right] > nums[right+1]:
                continue
            r = min(right-left, k+1)
            result += l*r
            left, l = right, r
        result += l*min(len(nums)-left, k+1)
        return result
