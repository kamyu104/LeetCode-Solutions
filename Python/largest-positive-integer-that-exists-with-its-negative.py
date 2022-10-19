# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def findMaxK(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lookup = set(nums)
        return max([x for x in lookup if x > 0 and -x in lookup] or [-1])
