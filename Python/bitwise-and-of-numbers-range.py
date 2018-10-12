# Time:  O(1)
# Space: O(1)

class Solution(object):
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        while m < n:
            n &= n - 1
        return n


class Solution2(object):
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        i, diff = 0, n-m
        while diff:
            diff >>= 1
            i += 1
        return n & m >> i << i

