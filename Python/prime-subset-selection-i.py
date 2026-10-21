# Time:  precompute: O(r)
#        runtime:    O(n / logn)
# Space: O(r)

# number theory, greedy
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
    return primes


MAX_N = 10**6
PRIMES = linear_sieve_of_eratosthenes(MAX_N)
class Solution(object):
    def maxPrimes(self, n, s):
        """
        :type n: int
        :type s: int
        :rtype: List[int]
        """
        result = []
        for x in PRIMES:
            if x > n or s-x < 0:
                break
            s -= x
            result.append(x)
        return result
