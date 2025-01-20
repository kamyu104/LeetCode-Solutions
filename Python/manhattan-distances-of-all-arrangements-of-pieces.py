# Time:  precompute: O(max(m * n))
#        runtime:    O(1)
# Space: O(max(m * n))

# combinatorics
MOD = 10**9+7
FACT, INV, INV_FACT = [[1]*2 for _ in xrange(3)]
def nCr(n, k):
    while len(INV) <= n:  # lazy initialization
        FACT.append(FACT[-1]*len(INV) % MOD)
        INV.append(INV[MOD%len(INV)]*(MOD-MOD//len(INV)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.append(INV_FACT[-1]*INV[-1] % MOD)
    return (FACT[n]*INV_FACT[n-k] % MOD) * INV_FACT[k] % MOD


class Solution(object):
    def distanceSum(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        def sum_n(n):
            return (n+1)*n//2

        def sum_n_square(n):
            return n*(n+1)*(2*n+1)//6

        def f(n):
            # sum((d*(n-d) for d in xrange(1, n)))
            return (n*sum_n(n-1)-sum_n_square(n-1))

        return (f(n)*m*m+f(m)*n*n)*nCr(m*n-2, k-2)%MOD
 
