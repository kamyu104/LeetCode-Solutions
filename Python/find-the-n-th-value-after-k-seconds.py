# Time:  O(n + k)
# Space: O(n + k)

# combinatorics
class Solution(object):
    def valueAfterKSeconds(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        def nCr(n, k):
            if not (0 <= k <= n):
                return 0
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD

        return nCr(n+k-1, k)


# Time:  O(n * k)
# Space: O(n)
# prefix sum
class Solution2(object):
    def valueAfterKSeconds(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        prefix = [1]*n
        for _ in range(k):
            for i in xrange(1, n):
                prefix[i] = (prefix[i]+prefix[i-1])%MOD
        return prefix[-1]

