# Time:  O(9 * (9 * n / 2) * (n / 2)) = O(n^2)
# Space: O((9 * n / 2) * (n / 2)) = O(n^2)

# dp, combinatorics
class Solution(object):
    def countBalancedPermutations(self, num):
        """
        :type num: str
        :rtype: int
        """
        MOD = 10**9+7
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        def lazy_init(n):
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)

        def nCr(n, k):
            lazy_init(n)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD

        def factorial(n):
            lazy_init(n)
            return fact[n]

        def inv_factorial(n):
            lazy_init(n)
            return inv_fact[n]
    
        total = sum(ord(x)-ord('0') for x in num)
        if total%2:
            return 0
        total //= 2
        cnt = [0]*10
        for x in num:
            cnt[ord(x)-ord('0')] += 1
        even = len(num)//2
        dp = [[0]*(even+1) for _ in xrange(total+1)]
        dp[0][0] = 1
        for i, x in enumerate(cnt):
            if not x:
                continue
            for j in reversed(xrange(total+1)):
                for k in reversed(xrange(even+1)):
                    if not dp[j][k]:
                        continue
                    for c in xrange(1, x+1):
                        if j+c*i <= total and k+c <= even:
                            dp[j+c*i][k+c] = (dp[j+c*i][k+c]+dp[j][k]*nCr(x, c))%MOD
        return dp[total][even]*factorial(even)*factorial(len(num)-even)*reduce(lambda accu, x: (accu*x)%MOD, (inv_factorial(x) for x in cnt), 1)%MOD
