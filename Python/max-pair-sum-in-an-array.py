# Time:  O(nlogr)
# Space: O(1)

# hash table
class Solution(object):
    def maxSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def max_digit(x):
            result = 0
            while x:
                x, r = divmod(x, 10)
                result = max(result, r)
            return result
    
        result = -1
        lookup = {}
        for x in nums:
            mx = max_digit(x)
            if mx not in lookup:
                lookup[mx] = x
                continue
            result = max(result, lookup[mx]+x)
            lookup[mx] = max(lookup[mx], x)
        return result
