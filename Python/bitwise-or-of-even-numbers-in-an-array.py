# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def evenNumberBitwiseORs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda total, x: total|(x if x%2 == 0 else 0), nums, 0)
