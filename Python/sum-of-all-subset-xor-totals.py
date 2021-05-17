# Time:  O(n)
# Space: O(1)

class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # given there are k (k >= 1) nums of which ith bit is 1,
        # the bit contributes to sum is:
        # (nCr(k, 1) + nCr(k, 3) + ...) * (nCr(n - k, 0) + nCr(n - k, 1) + ...) * 2^i
        # = 2^(k-1) * 2^(n-k) = 2^(n-1) * 2^i
        result = 0
        for x in nums:
            result |= x
        return result * 2**(len(nums)-1)
