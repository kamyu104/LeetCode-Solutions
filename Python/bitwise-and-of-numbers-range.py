# Time:  O(1)
# Space: O(1)
#
# Given a range [m, n] where 0 <= m <= n <= 2147483647, 
# return the bitwise AND of all numbers in this range, inclusive.
#
# For example, given the range [5, 7], you should return 4.
#

class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        while m < n:
            n &= n - 1
        return n

class Solution2:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        i, diff = 0, n-m
        while diff:
            diff >>= 1
            i += 1
        return n&m >> i << i

if __name__ == '__main__':
    print Solution().rangeBitwiseAnd(5, 7)
