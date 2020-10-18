# Time:  O(min(k, min(n - k)))
# Space: O(1)

class Solution(object):
    def numberOfSets(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        def nCr(n, r):  # Time: O(n), Space: O(1)
            if n-r < r:
                return nCr(n, n-r)
            c = 1
            for k in xrange(1, r+1):
                c *= n-k+1
                c //= k
            return c
        
        # find k segments with 1+ length and (k+1) spaces with 0+ length s.t. total length is n-1
        # => find k segments with 0+ length and (k+1) spaces with 0+ length s.t. total length is n-k-1
        # => find the number of combinations of 2k+1 variables with total sum n-k-1
        # => H(2k+1, n-k-1)
        # => C((2k+1) + (n-k-1) - 1, n-k-1)
        # => C(n+k-1, n-k-1) = C(n+k-1, 2k)
        return nCr(n+k-1, 2*k) % MOD
