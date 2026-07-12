# Time:  precompute: O(r)
#        runtime:    O(nlogx + f) = O(nlogx), f = sum of distinct prime factors over all nums (<= 7n)
# Space: O(r + n)

import collections


# number theory, kadane's algorithm, prefix sum
def linear_sieve_of_eratosthenes(n):  # Time: O(n), Space: O(n)
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


MAX_NUMS = 10**6
SPF = linear_sieve_of_eratosthenes(MAX_NUMS)
class Solution(object):
    def divisibleGame(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        lookup = collections.defaultdict(list)
        for i, x in enumerate(nums):
            while x != 1:
                p = SPF[x]
                lookup[p].append(i)
                while x%p == 0:
                    x //= p
        best_diff, best_k = -min(nums), 2
        for p, idxs in lookup.iteritems():
            total, j = 0, -1
            for i in idxs:
                total = max(total-(prefix[(i-1)+1]-prefix[j+1]), 0)+nums[i]
                if total > best_diff:
                    best_diff, best_k = total, p
                elif total == best_diff:
                    best_k = min(best_k, p)
                j = i
        return (best_diff*best_k)%MOD
