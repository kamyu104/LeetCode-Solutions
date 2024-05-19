# Time:  O(logk)
# Space: O(logk)

# combinatorics
class Solution(object):
    def waysToReachStair(self, k):
        """
        :type k: int
        :rtype: int
        """
        def ceil_log2_x(x):
            return (x-1).bit_length()

        l = ceil_log2_x(k)
        while (1<<l)-k <= l+1:
            l += 1
        fact = [1]*(l+1)
        for i in xrange(len(fact)-1):
            fact[i+1] = fact[i]*(i+1)
        def nCr(n, r):
            if not (0 <= r <= n):
                return 0
            return fact[n]//fact[r]//fact[n-r]

        return sum(nCr(i+1, (1<<i)-k) for i in xrange(l))
