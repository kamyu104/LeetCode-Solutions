# Time:  O(1)
# Space: O(1)

# bit manipulation
class Solution(object):
    def evenOddBit(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def popcount(x):
            return bin(x)[2:].count('1')

        return [popcount(n&0b0101010101), popcount(n&0b1010101010)]
