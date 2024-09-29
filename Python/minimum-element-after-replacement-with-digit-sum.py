# Time:  O(nlogr)
# Space: O(1)

# array
class Solution(object):
    def minElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def f(x):
            result = 0
            while x:
                result += x%10
                x //= 10
            return result

        return min(f(x) for x in nums)
