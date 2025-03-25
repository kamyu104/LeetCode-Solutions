# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def maxSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(nums)
        return mx if mx < 0 else sum(x for x in set(nums) if x >= 0)
