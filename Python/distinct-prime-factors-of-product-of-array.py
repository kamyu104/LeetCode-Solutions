# Time:  precompute: O(sqrt(MAX_N))
#        runtime:    O(m + nlog(logn)), m = len(nums), n = max(nums)
# Space: O(sqrt(MAX_N))

# number theory
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
    return primes  # len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n


MAX_N = 10**3
PRIMES = linear_sieve_of_eratosthenes(int(MAX_N**0.5))  
class Solution(object):
    def distinctPrimeFactors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = set()
        for x in set(nums):  # Time: O(n/p1 + n/p2 + ... + n/pk) = O(n * (1/p1 + 1/p2 + ... + 1/pk)) = O(nlog(logn))
            for p in PRIMES:
                if p > x:
                    break
                if x%p:
                    continue
                result.add(p)
                while x%p == 0:
                    x //= p
            if x != 1:  # x is a prime
                result.add(x)
        return len(result)
