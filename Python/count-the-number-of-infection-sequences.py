# Time:  O(n)
# Space: O(n)

# combinatorics
fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
class Solution(object):
    def numberOfSequence(self, n, sick):
        """
        :type n: int
        :type sick: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def nCr(n, k):
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD
        
        result = 1
        total = 0
        for i in xrange(len(sick)+1):
            l = (sick[i] if i < len(sick) else n)-(sick[i-1] if i-1 >= 0 else -1)-1
            if i not in (0, len(sick)):
                result = (result*pow(2, max(l-1, 0), MOD))%MOD
            total += l
            result = (result*nCr(total, l))%MOD
        return result
