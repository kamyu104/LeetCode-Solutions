# Time:  precompute:  O(sqrt(r)), r = max(nums)
#        runtime:     O(n * logr)
# Space: O(sqrt(r))

import collections


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


MAX_NUM = 10**6
PRIMES = linear_sieve_of_eratosthenes(int(MAX_NUM**0.5+0.5))
# number theory
class Solution(object):
    def findValidSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def factorize(x):
            result = []
            for d in PRIMES:
                if d > x:
                    break
                e = 0
                while x%d == 0:
                    x //= d
                    e += 1
                if e:
                    result.append([d, e])
            if x > 1:
                result.append([x, 1])
            return result
        
        right = collections.Counter()
        for x in reversed(nums):
            for p, c in factorize(x):
                right[p] += c
        left = collections.Counter()
        cnt = 0
        for i in xrange(len(nums)-1):
            for p, c in factorize(nums[i]):
                if not left[p]:
                    cnt += 1
                left[p] += c
                right[p] -= c
                if not right[p]:
                    cnt -= 1
            if not cnt:
                return i
        return -1


# Time:  O(n * sqrt(r)), r = max(nums)
# Space: O(sqrt(r))
import collections


# number theory
class Solution(object):
    def findValidSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def factorize(x):
            result = []
            d = 2
            while d*d <= x:
                e = 0
                while x%d == 0:
                    x //= d
                    e += 1
                if e:
                    result.append([d, e])
                d += 1 if d == 2 else 2
            if x > 1:
                result.append([x, 1])
            return result
        
        right = collections.Counter()
        for x in reversed(nums):
            for p, c in factorize(x):
                right[p] += c
        left = collections.Counter()
        cnt = 0
        for i in xrange(len(nums)-1):
            for p, c in factorize(nums[i]):
                if not left[p]:
                    cnt += 1
                left[p] += c
                right[p] -= c
                if not right[p]:
                    cnt -= 1
            if not cnt:
                return i
        return -1
