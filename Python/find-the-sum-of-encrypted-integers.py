# Time:  O(nlogr)
# Space: O(1)

# array
class Solution(object):
    def sumOfEncryptedInt(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def f(x):
            mx = base = 0
            while x:
                mx = max(mx, x%10)
                x //= 10
                base = 10*base+1
            return mx*base

        return sum(f(x) for x in nums)
