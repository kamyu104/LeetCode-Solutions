# Time:  O(min(n, k))
# Space: O(1)

# constructive algorithms
class Solution(object):
    def maximumTop(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums) == 1 == k%2:
            return -1
        if k <= 1:
            return nums[k]
        return max(nums[i] for i in xrange(min(k+1, len(nums))) if i != k-1)
