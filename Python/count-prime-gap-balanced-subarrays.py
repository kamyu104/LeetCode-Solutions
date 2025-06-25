# Time:  precompute: O(r), r = max(nums)
#        runtime:    O(n)
# Space: O(r)

import collections


# number theory, mono deque, two pointers, sliding window
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


MAX_NUMS = 5*10**4
SPF = linear_sieve_of_eratosthenes(MAX_NUMS)
class Solution(object):
    def primeSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        idxs, max_dq, min_dq = collections.deque(), collections.deque(), collections.deque()
        result = left = 0
        for right in xrange(len(nums)):
            if SPF[nums[right]] == nums[right]:
                idxs.append(right)
                while max_dq and nums[max_dq[-1]] <= nums[right]:
                    max_dq.pop()
                max_dq.append(right)
                while min_dq and nums[min_dq[-1]] >= nums[right]:
                    min_dq.pop()
                min_dq.append(right)
                while nums[max_dq[0]]-nums[min_dq[0]] > k:
                    if min_dq[0] == left:
                        min_dq.popleft()
                    if max_dq[0] == left:
                        max_dq.popleft()
                    if idxs[0] == left:
                        idxs.popleft()
                    left += 1
            if len(idxs) >= 2:
                result += idxs[-2]-left+1
        return result
