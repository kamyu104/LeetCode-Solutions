# Time:  O(nlogr), r = max(nums)
# Space: O(1)

# greedy
class Solution(object):
    def minimumSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        result, g = 1, 0
        for x in nums:
            g = gcd(g, x)
            if g == 1:
                g = x
                result += 1
        return result
