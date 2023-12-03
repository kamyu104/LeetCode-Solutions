# Time:  precompute: O(max_n)
#        runtime:    O(s + logn)
# Space: O(max_n)

# combinatorics
FACT, INV, INV_FACT = [[1]*2 for _ in xrange(3)]
class Solution(object):
    def numberOfSequence(self, n, sick):
        """
        :type n: int
        :type sick: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def nCr(n, k):
            while len(INV) <= n:  # lazy initialization
                FACT.append(FACT[-1]*len(INV) % MOD)
                INV.append(INV[MOD%len(INV)]*(MOD-MOD//len(INV)) % MOD)  # https://cp-algorithms.com/algebra/module-INVerse.html
                INV_FACT.append(INV_FACT[-1]*INV[-1] % MOD)
            return (FACT[n]*INV_FACT[n-k] % MOD) * INV_FACT[k] % MOD
        
        result = 1
        total = cnt = 0
        for i in xrange(len(sick)+1):
            l = (sick[i] if i < len(sick) else n)-(sick[i-1] if i-1 >= 0 else -1)-1
            if i not in (0, len(sick)):
                cnt += max(l-1, 0)
            total += l
            result = (result*nCr(total, l))%MOD
        result = (result*pow(2, cnt, MOD))%MOD
        return result
