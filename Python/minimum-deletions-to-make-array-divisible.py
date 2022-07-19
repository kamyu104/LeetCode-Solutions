# Time:  O(n + m + logr), r is max(numsDivide)
# Space: O(1)

# gcd
class Solution(object):
    def minOperations(self, nums, numsDivide):
        """
        :type nums: List[int]
        :type numsDivide: List[int]
        :rtype: int
        """
        def gcd(a, b):  # Time: O(log(min(a, b)))
            while b:
                a, b = b, a%b
            return a

        g = reduce(gcd, numsDivide)
        mn = float("inf")
        for x in nums:
            if g%x == 0:
                mn = min(mn, x)
        return sum(x < mn for x in nums) if mn != float("inf") else -1
