# Time:  precompute: O(MAX_N)
#        runtime:    O(n)
# Space: O(MAX_N)

import collections


# number theory, freq table
def linear_sieve_of_eratosthenes(n):
    primes = []
    spf = [-1]*(n+1)  # the smallest prime factor
    for i in xrange(2, n+1):
        if spf[i] == -1:
            spf[i] = i
            primes.append(i)
        for p in primes:
            if i*p > n or p > spf[i]:
                break
            spf[i*p] = p
    return spf


MAX_N = 100
SPF = linear_sieve_of_eratosthenes(MAX_N)
class Solution(object):
    def checkPrimeFrequency(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        return any(SPF[v] == v for v in cnt.itervalues())
