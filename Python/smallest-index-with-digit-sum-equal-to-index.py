# Time:  O(nlogr)
# Space: O(1)

# array
class Solution(object):
    def smallestIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def total(x):
            result = 0
            while x:
                result += x%10
                x //= 10
            return result

        return next((i for i, x in enumerate(nums) if total(x) == i), -1)
