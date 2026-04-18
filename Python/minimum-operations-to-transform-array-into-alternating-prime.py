# Time:  precompute: O(r)
#        runtime:    O(nlogr), prime gap is ln(r) on average
# Space: O(r)

# number theory, prime gap
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


MAX_NUMS = 10**5+3
PRIMES, SPF = linear_sieve_of_eratosthenes(MAX_NUMS)
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = curr = 0
        for i, x in enumerate(nums):
            if i%2 == 0:
                while SPF[x] != x:
                    x += 1
                    result += 1
            else:
                while SPF[x] == x:
                    x += 1
                    result += 1
        return result


# Time:  precompute: O(r)
#        runtime:    O(nlogn)
# Space: O(r)
import bisect


# number theory, binary search
class Solution2(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = curr = 0
        for i, x in enumerate(nums):
            if i%2 == 0:
                result += PRIMES[bisect.bisect_left(PRIMES, x)]-x
            else:
                result += 2 if x == 2 else 1 if SPF[x] == x else 0
        return result
