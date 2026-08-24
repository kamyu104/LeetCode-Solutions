# Time:  ctor:    O(r)
#        runtime: O(nlogr)
# Space: O(r)

# number theory, freq table, two pointers
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


MAX_NUMS = 10**5
SPF = linear_sieve_of_eratosthenes(MAX_NUMS)
class Solution(object):
    def longestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def prime_factors(x):
            cnt = collections.defaultdict(int)
            while x != 1:
                cnt[SPF[x]] += 1
                x //= SPF[x]
            return cnt

        cnt = collections.defaultdict(int)
        left = 0
        for x in nums:
            for p, c in prime_factors(x).iteritems():
                cnt[p] += c
            if len(cnt) <= k:
                continue
            for p, c in prime_factors(nums[left]).iteritems():
                cnt[p] -= c
                if not cnt[p]:
                    del cnt[p]
            left += 1
        return len(nums)-left


# Time:  ctor:    O(r)
#        runtime: O(nlogr)
# Space: O(r)
import collections


# number theory, freq table, two pointers
class Solution2(object):
    def longestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def prime_factors(x):
            cnt = collections.defaultdict(int)
            y = x
            while x != 1:
                cnt[SPF[x]] += 1
                x //= SPF[x]
            return cnt

        cnt = collections.defaultdict(int)
        result = left = 0
        for right, x in enumerate(nums):
            for p, c in prime_factors(x).iteritems():
                cnt[p] += c
            while len(cnt) > k:
                for p, c in prime_factors(nums[left]).iteritems():
                    cnt[p] -= c
                    if not cnt[p]:
                        del cnt[p]
                left += 1
            result = max(result, right-left+1)
        return result
