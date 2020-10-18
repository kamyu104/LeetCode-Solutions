# Time:  O(1), excluding precomputation time
# Space: O(n)

# precompute
MOD = 10**9+7
MAX_N = 1000
fact = [0]*(2*MAX_N-1+1)
inv = [0]*(2*MAX_N-1+1)
inv_fact = [0]*(2*MAX_N-1+1)
fact[0] = inv_fact[0] = fact[1] = inv_fact[1] = inv[1] = 1
for i in xrange(2, len(fact)):
    fact[i] = fact[i-1]*i % MOD
    inv[i] = inv[MOD%i]*(MOD-MOD//i) % MOD  # https://cp-algorithms.com/algebra/module-inverse.html
    inv_fact[i] = inv_fact[i-1]*inv[i] % MOD

class Solution(object):
    def numberOfSets(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def nCr(n, k, mod):
            return (fact[n]*inv_fact[n-k] % mod) * inv_fact[k] % mod
    
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
