# Time:  precompute: O(r * log(logr)), r = MAX_NUM
#        runtime:    O(n * log(logr))
# Space: O(r * log(logr))

import collections


# number theory, hash table
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
    return primes  # len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n

def prime_divisors(n):
    result = [[] for _ in xrange(n+1)]
    for p in linear_sieve_of_eratosthenes(n):  # Time: O(nlog(logn))
        for i in range(p, n+1, p):
            result[i].append(p)
    return result

MAX_NUM = 10
PRIME_DIVISORS = prime_divisors(MAX_NUM)
class Solution(object):
    def maxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 2
        lookup = collections.defaultdict(int)
        left = 0
        for right, x in enumerate(nums):
            for p in PRIME_DIVISORS[x]:
                left = max(left, lookup[p])
                lookup[p] = right+1
            result = max(result, right-left+1)
        return result
