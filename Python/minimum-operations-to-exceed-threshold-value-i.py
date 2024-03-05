# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sum(x < k for x in nums)
