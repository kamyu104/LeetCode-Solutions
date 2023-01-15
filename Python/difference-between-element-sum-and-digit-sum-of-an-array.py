# Time:  O(nlogr), r = max(nums)
# Space: O(1)

# array
class Solution(object):
    def differenceOfSum(self, nums):
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

        return abs(sum(nums)-sum(total(x) for x in nums))
