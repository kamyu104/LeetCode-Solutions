# Time:  precompute: O(sqrt(r))
#        runtime:    O(sqrt(n) / logn)
# Space: O(sqrt(r))

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


MAX_N = 10**9
PRIMES = linear_sieve_of_eratosthenes(int(sqrt(MAX_N)))
class Solution(object):
    def minimumMaxValue(self, n, index, value):
        """
        :type n: int
        :type index: int
        :type value: int
        :rtype: int
        """
        if value == 1:
            return -1
        x = value
        for p in PRIMES:
            if p*p > value:
                break
            if value%p == 0:
                x = p
                break
        if value-x-2*(index-1) < 2:
            return -1
        return value+x+2*(((n-1)-index)-1) if index != n-1 else value
