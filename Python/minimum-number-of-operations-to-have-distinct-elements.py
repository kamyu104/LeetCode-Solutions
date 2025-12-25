# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        L = 3
        def ceil_divide(a, b):
            return (a+b-1)//b

        lookup = set()
        while nums:
            if nums[-1] in lookup:
                break
            lookup.add(nums.pop())
        return ceil_divide(len(nums), L)
