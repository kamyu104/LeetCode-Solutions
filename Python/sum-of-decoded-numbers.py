# Time:  O(nlogr)
# Space: O(1)

# fast exponentiation
class Solution(object):
    def sumDecoded(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def length(x):
            result = 0
            while x:
                x //= 10
                result += 1
            return result
        
        result = 0
        for v in nums:
            d, w = divmod(v, 10)
            x, y = divmod(d, 10**(length(d)-w))
            result = (result+pow(x, y, MOD))%MOD
        return result
