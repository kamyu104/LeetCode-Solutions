# Time:  precompute: O(max(m * n))
#        runtime:    O(1)
# Space: O(max(m * n))

# combinatorics
class Solution(object):
    def distanceSum(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        def nCr(n, k):
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD

        def sum_n(n):
            return (n+1)*n//2

        def sum_n_square(n):
            return n*(n+1)*(2*n+1)//6

        def f(n):
            # sum((d*(n-d) for d in xrange(1, n)))
            return (n*sum_n(n-1)-sum_n_square(n-1))

        return (f(n)*m*m+f(m)*n*n)*nCr(m*n-2, k-2)%MOD
 
