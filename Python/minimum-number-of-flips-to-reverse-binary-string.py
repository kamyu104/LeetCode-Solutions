# Time:  O(logn)
# Space: O(1)

# bitmasks
class Solution(object):
    def minimumFlips(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = n.bit_length()
        return sum(2 for i in xrange(l//2) if (n>>i)&1 != (n>>((l-1)-i))&1)
