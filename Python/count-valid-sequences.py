# Time:  O(n)
# Space: O(n)

# stars and bars, combinatorics
MOD = 10**9+7
FACT, INV, INV_FACT = [[1]*2 for _ in xrange(3)]
MAX_N = 5*10**5
while len(INV) <= MAX_N:  # lazy initialization
    FACT.append(FACT[-1]*len(INV) % MOD)
    INV.append(INV[MOD%len(INV)]*(MOD-MOD//len(INV)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
    INV_FACT.append(INV_FACT[-1]*INV[-1] % MOD)

class Solution(object):
    def countValidSequences(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def nCr(n, k):
            return (FACT[n]*INV_FACT[n-k] % MOD) * INV_FACT[k] % MOD
    
        def nHr(n, k):
            return nCr(n+k-1, k)

        return (nHr(k, n-k)-(nHr(k, (n-k)//2) if (n-k)%2 == 0 else 0))%MOD
