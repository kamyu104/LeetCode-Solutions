# Time:  O(n)
# Space: O(1)

# one pass, array
class Solution(object):
    def findNonMinOrMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx, mn = float("-inf"), float("inf")
        result = -1
        for x in nums:
            if mn < x < mx:
                return x
            if x < mn:
                result = mn
                mn = x
            if x > mx:
                result = mx
                mx = x
        return result if mn < result < mx else -1


# Time:  O(n)
# Space: O(1)
# array
class Solution2(object):
    def findNonMinOrMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx, mn = max(nums), min(nums)
        return next((x for x in nums if x not in (mx, mn)), -1)
