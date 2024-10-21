# Time:  precompute: O(r)
#        runtime:    O(n)
# Space: O(r) 

# greedy, number theory
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
    return spf

MAX_N = 10**6
SPF = linear_sieve_of_eratosthenes(MAX_N)
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in reversed(xrange(len(nums)-1)):
            if nums[i] <= nums[i+1]:
                continue
            if SPF[nums[i]] > nums[i+1]:
                return -1
            nums[i] = SPF[nums[i]]
            result += 1
        return result
