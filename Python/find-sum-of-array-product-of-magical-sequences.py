# Time:  O(n * k * m^2)
# Space: O(k * m^2)

# dp, combinatorics
class Solution(object):
    def magicalSum(self, m, k, nums):
        """
        :type m: int
        :type k: int
        :type nums: List[int]
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        MOD = 10**9+7
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        for _ in xrange(m+1):
            fact.append(fact[-1]*len(inv) % MOD)
            inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
        dp = [[[0]*(m+1) for _ in xrange(k+1)] for _ in xrange(m+1)]  # dp[c][b][l]: sum of carry c with b set bits with remain size of l
        dp[0][0][m] = 1
        for x in nums:
            new_dp = [[[0]*(m+1) for _ in xrange(k+1)] for _ in xrange(m+1)]
            for c in xrange(m+1):
                for b in xrange(k+1):
                    for l in xrange(m+1):
                        if not dp[c][b][l]:
                            continue
                        base = 1
                        for cnt in xrange(l+1):
                            nc, nb, nl  = (c+cnt)>>1, b+((c+cnt)&1), l-cnt
                            if nb > k:
                                continue
                            new_dp[nc][nb][nl] = (new_dp[nc][nb][nl]+dp[c][b][l]*base*inv_fact[cnt]) % MOD
                            base = (base*x)%MOD
            dp = new_dp
        return (reduce(lambda accu, x: (accu+x)%MOD, (dp[c][k-popcount(c)][0] for c in xrange(m+1) if k-popcount(c) >= 0), 0)*fact[m])%MOD



# Time:  O(n * k * m^2)
# Space: O(k * m^2)
# dp, combinatorics
class Solution2(object):
    def magicalSum(self, m, k, nums):
        """
        :type m: int
        :type k: int
        :type nums: List[int]
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        MOD = 10**9+7
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        def nCr(n, k):
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD

        dp = [[[0]*(m+1) for _ in xrange(k+1)] for _ in xrange(m+1)]  # dp[c][b][l]: sum of carry c with b set bits with remain size of l
        dp[0][0][m] = 1
        for x in nums:
            new_dp = [[[0]*(m+1) for _ in xrange(k+1)] for _ in xrange(m+1)]
            for c in xrange(m+1):
                for b in xrange(k+1):
                    for l in xrange(m+1):
                        if not dp[c][b][l]:
                            continue
                        base = 1
                        for cnt in xrange(l+1):
                            nc, nb, nl  = (c+cnt)>>1, b+((c+cnt)&1), l-cnt
                            if nb > k:
                                continue
                            new_dp[nc][nb][nl] = (new_dp[nc][nb][nl]+dp[c][b][l]*base*nCr(l, cnt)) % MOD
                            base = (base*x)%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (dp[c][k-popcount(c)][0] for c in xrange(m+1) if k-popcount(c) >= 0), 0)

