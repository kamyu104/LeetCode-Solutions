# Time:  O(n)
# Space: O(1)

# greedy, math
class Solution(object):
    def minimumReplacement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        result = 0
        curr = nums[-1]
        for x in reversed(nums):
            cnt = ceil_divide(x, curr)
            result += cnt-1
            curr = x//cnt
        return result
