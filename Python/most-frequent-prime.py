# Time:  precompute: O(10^MAX_N_M)
#        runtime:    O(n * m * (n + m))
# Space: O(10^MAX_N_M + n * m * (n + m))

import collections


# number theory, freq table
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


MAX_M_N = 6
SPF = linear_sieve_of_eratosthenes(10**MAX_M_N-1)
class Solution(object):
    def mostFrequentPrime(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1))
        def numbers(i, j, di, dj):
            curr = 0
            while 0 <= i < len(mat) and 0 <= j < len(mat[0]):
                curr = curr*10+mat[i][j]
                yield curr
                i, j = i+di, j+dj

        cnt = collections.Counter(x for i in xrange(len(mat)) for j in xrange(len(mat[0])) for di, dj in DIRECTIONS for x in numbers(i, j, di, dj) if x > 10 and SPF[x] == x)
        cnt[-1] = 0
        return max(cnt.iterkeys(), key=lambda x: (cnt[x], x))


# Time:  O(n * m * (n + m) * sqrt(10^MAX_N_M))
# Space: O(n * m * (n + m))
import collections


# number theory, freq table
def is_prime(n):
    if n%2 == 0 or n%3 == 0:
        return False
    for i in xrange(5, n, 6):
        if i*i > n:
            break
        if n%i == 0 or n%(i+2) == 0:
            return False
    return True  


class Solution2(object):
    def mostFrequentPrime(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1))
        def numbers(i, j, di, dj):
            curr = 0
            while 0 <= i < len(mat) and 0 <= j < len(mat[0]):
                curr = curr*10+mat[i][j]
                yield curr
                i, j = i+di, j+dj

        cnt = collections.Counter(x for i in xrange(len(mat)) for j in xrange(len(mat[0])) for di, dj in DIRECTIONS for x in numbers(i, j, di, dj) if x > 10)
        cnt[-1] = 0
        return max((p for p in cnt.iterkeys() if is_prime(p) or p == -1), key=lambda x: (cnt[x], x))
