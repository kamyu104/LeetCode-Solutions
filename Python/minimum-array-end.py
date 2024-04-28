# Time:  O(logn)
# Space: O(1)

# bit manipulation
class Solution(object):
    def minEnd(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: int
        """
        n -= 1
        base_n = base_x = 1
        while base_n <= n:
            if (x&base_x) == 0:
                if n&base_n:
                    x |= base_x
                base_n <<= 1
            base_x <<= 1
        return x
