# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len({x for x in nums if x})
