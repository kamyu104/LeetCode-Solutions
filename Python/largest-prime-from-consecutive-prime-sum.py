# Time:  precompute: O(sqrt(r) * sqrt(r)) = O(r)
#        runtime:    O(logp), p = len(PRIMES)
# Space: O(sqrt(r))

import bisect


# precompute, number theory, binary search
def is_prime(n):
    if (n <= 1) or (n != 2 and n%2 == 0):
        return False
    for i in xrange(3, n+1, 2):
        if i*i > n:
            break
        if n%i == 0:
            return False
    return True


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
    return primes, spf


def precompute(n, sqrt_n):
    result = [0]
    primes, spf = linear_sieve_of_eratosthenes(sqrt_n)
    total = 0
    for p in primes:
        total += p
        if total > n:
            break
        if (total < len(spf) and spf[total] == total) or is_prime(total):
            result.append(total)
    return result


MAX_NUM = 5*10**5
SQRT_MAX_NUM = 2729  # by precomputation
PRIMES = precompute(MAX_NUM, SQRT_MAX_NUM)
class Solution(object):
    def largestPrime(self, n):
        """
        :type n: int
        :rtype: int
        """
        return PRIMES[bisect.bisect_right(PRIMES, n)-1]
