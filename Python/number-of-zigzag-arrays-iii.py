# Time:  O(n^3)
# Space: O(n)

# dp, prefix sum, combinatorics, lagrange interpolation
class Solution(object):
    def zigZagArrays(self, n, l, r):
        """
        :type n: int
        :type l: int
        :type r: int
        :rtype: int
        """
        MOD = 10**9+7
        inv, inv_fact = [[1]*2 for _ in xrange(2)]
        def inv_factorial(n):
            while len(inv) <= n:  # lazy initialization
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return inv_fact[n]
    
        def f(x):
            dp = range(x)
            for _ in xrange(n-2):
                new_up = [0]*x
                for i in xrange(x-1):
                    new_up[i+1] = (new_up[i]+dp[~i])%MOD
                dp = new_up
            return (reduce(lambda accu, x: (accu+x)%MOD, dp, 0)*2)%MOD

        m = r-l+1
        if m <= n+1:
            return f(m)
        y = [f(x) for x in xrange(1, (n+1)+1)]
        prefix = [0]*(len(y)+1)
        prefix[0] = 1
        for i in xrange(len(prefix)-1):
            prefix[i+1] = prefix[i]*(m-1-i)%MOD
        suffix = [0]*(len(y)+1)
        suffix[-1] = 1
        for i in reversed(xrange(len(suffix)-1)):
            suffix[i] = suffix[i+1]*(m-1-i)%MOD
        return reduce(lambda accu, x: (accu+x)%MOD, (y[i]*(prefix[i]*suffix[i+1])*(inv_factorial(i)*inv_factorial(n-i)*(-1 if (n-i)%2 else 1)) for i in xrange(n+1)), 0)
