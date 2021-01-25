# Time:  O(nlogn)
# Space: O(logn)

import collections


MAX_N = 10**4 
MOD = 10**9+7
MAX_F = MAX_N.bit_length()-1  # floor_log2_MAX_N
fact = [0]*((MAX_F+MAX_N-1)+1)
inv = [0]*((MAX_F+MAX_N-1)+1)
inv_fact = [0]*((MAX_F+MAX_N-1)+1)
fact[0] = inv_fact[0] = fact[1] = inv_fact[1] = inv[1] = 1
for i in xrange(2, len(fact)):
    fact[i] = fact[i-1]*i % MOD
    inv[i] = inv[MOD%i]*(MOD-MOD//i) % MOD  # https://cp-algorithms.com/algebra/module-inverse.html
    inv_fact[i] = inv_fact[i-1]*inv[i] % MOD

sieve = range(MAX_N+1)
for i in xrange(2, MAX_N+1):
    if sieve[i] != i:
        continue
    for j in xrange(i*i, MAX_N+1, i):
        sieve[j] = i

class Solution(object):
    def waysToFillArray(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def nCr(n, k, mod):
            return (fact[n]*inv_fact[n-k] % mod) * inv_fact[k] % mod
        
        def get_factors(k):
            factors = collections.Counter()
            while k > 1:
                factors[sieve[k]] += 1
                k //= sieve[k]
            return factors

        result = []
        for n, k in queries:
            factors = get_factors(k)
            curr = 1
            for f in factors.itervalues():
                curr *= nCr(f+n-1,f, MOD)  # H(n, f)
            result.append(curr % MOD)
        return result
