# Time:  O(m * nlogn)
# Space: O(1)

# sort
class Solution(object):
    def matrixSum(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: int
        """
        for row in nums:
            row.sort()
        return sum(max(nums[r][c] for r in xrange(len(nums))) for c in xrange(len(nums[0])))
