# Time:  O(n)
# Space: O(1)

# prefix sum, hash table
class Solution(object):
    def maxValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = mn = 0
        lookup = [float("-inf"), 0]
        for i, x in enumerate(nums):
            prefix += x*(1 if i%2 == 0 else -1)
            mn = min(mn, prefix-lookup[i%2])
            lookup[i%2] = max(lookup[i%2], prefix)
        return prefix-2*mn
