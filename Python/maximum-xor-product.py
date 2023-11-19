# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maximumXorProduct(self, a, b, n):
        """
        :type a: int
        :type b: int
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        for i in reversed(xrange(n)):
            base = 1<<i
            if a&base == b&base:
                a, b = a|base, b|base
                continue
            if a > b:
                a, b = b, a
            a, b = a|base, b&~base
        return (a%MOD)*(b%MOD)%MOD
