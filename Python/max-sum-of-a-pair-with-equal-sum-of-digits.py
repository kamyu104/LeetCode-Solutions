# Time:  O(nlogr), r is max(nums)
# Space: O(n)

# greedy
class Solution(object):
    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def sum_digits(x):
            result = 0
            while x:
                result += x%10
                x //= 10
            return result

        lookup = {}
        result = -1
        for x in nums:
            k = sum_digits(x)
            if k not in lookup:
                lookup[k] = x
                continue
            result = max(result, lookup[k]+x)
            if x > lookup[k]:
                lookup[k] = x
        return result
