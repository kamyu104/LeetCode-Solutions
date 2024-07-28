# Time:  precompute:  O(sqrt(r))
#        runtime:     O(logr + log(sqrt(r))) = O(logr)
# Space: O(sqrt(r))

import bisect


# number theory, binary search
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


MAX_R = 10**9
PRIMES = linear_sieve_of_eratosthenes(int(MAX_R**0.5))
class Solution(object):
    def nonSpecialCount(self, l, r):
        """
        :type l: int
        :type r: int
        :rtype: int
        """
        def count(x):
            return x-bisect.bisect_right(PRIMES, int(x**0.5))

        return count(r)-count(l-1)
