# Time:  O(nlogn)
# Space: O(1)

# sort, combinatorics, dp
class Solution(object):
    def sumOfPower(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        nums.sort()
        result = dp = 0
        for x in nums:
            result = (result+(x**2)*(dp+x))%MOD
            dp = (dp+(dp+x))%MOD
        return result
