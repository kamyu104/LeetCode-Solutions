# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minimizeArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        result = curr = 0
        for i, x in enumerate(nums):
            curr += x
            result = max(result, ceil_divide(curr, i+1))
        return result
