# Time:  precompute: O(MAX_N)
#        runtime: O(n)
# Space: O(MAX_N)

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


MAX_N = 4*10**6
PRIMES = linear_sieve_of_eratosthenes(MAX_N)
PRIMES_SET = set(PRIMES)
class Solution(object):
    def diagonalPrime(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: int
        """
        result = 0
        for i in xrange(len(nums)):
            if nums[i][i] in PRIMES_SET:
                result = max(result, nums[i][i])
            if nums[i][~i] in PRIMES_SET:
                result = max(result, nums[i][~i])
        return result
