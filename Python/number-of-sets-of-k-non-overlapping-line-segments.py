# Time:  O(1), excluding precomputation time
# Space: O(n)

class Solution(object):
    def __init__(self):
        MOD = 10**9+7
        MAX_N = 1000
        self.__fact = [0]*(2*MAX_N-1+1)
        self.__inv = [0]*(2*MAX_N-1+1)
        self.__inv_fact = [0]*(2*MAX_N-1+1)
        self.__fact[0] = self.__inv_fact[0] = self.__fact[1] = self.__inv_fact[1] = self.__inv[1] = 1
        for i in xrange(2, len(self.__fact)):
            self.__fact[i] = self.__fact[i-1]*i % MOD
            self.__inv[i] = self.__inv[MOD%i]*(MOD-MOD//i) % MOD  # https://cp-algorithms.com/algebra/module-inverse.html
            self.__inv_fact[i] = self.__inv_fact[i-1]*self.__inv[i] % MOD

    def numberOfSets(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        def nCr(n, k, mod):
            return (self.__fact[n]*self.__inv_fact[n-k] % mod) * self.__inv_fact[k] % mod
    
        # find k segments with 1+ length and (k+1) spaces with 0+ length s.t. total length is n-1
        # => find k segments with 0+ length and (k+1) spaces with 0+ length s.t. total length is n-k-1
        # => find the number of combinations of 2k+1 variables with total sum n-k-1
        # => H(2k+1, n-k-1)
        # => C((2k+1) + (n-k-1) - 1, n-k-1)
        # => C(n+k-1, n-k-1) = C(n+k-1, 2k)
        return nCr(n+k-1, 2*k, MOD)


# Time:  O(min(k, min(n - k)))
# Space: O(1)
class Solution2(object):
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
