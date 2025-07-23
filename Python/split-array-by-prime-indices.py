# Time:  precompute: O(max_n), max_n = max(len(nums))
#        runtime:    O(n)
# Space: O(max_n)

# number theory
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


MAX_IDX = 10**5-1
SPF = linear_sieve_of_eratosthenes(MAX_IDX)
class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return abs(sum(x if SPF[i] == i else -x for i, x in enumerate(nums)))
