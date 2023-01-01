# Time:  precompute:  O(MAX_N * log(MAX_N))
#        runtime:     O(log(MAX_N))
# Space: O(MAX_N)

import bisect


# Template:
# https://github.com/kamyu104/LeetCode-Solutions/blob/master/Python/booking-concert-tickets-in-groups.py
class SegmentTree(object):
    def __init__(self, N, build_fn, query_fn):
        self.tree = [None]*(2*2**((N-1).bit_length()))
        self.base = len(self.tree)//2
        self.query_fn = query_fn
        for i in xrange(self.base, self.base+N):
            self.tree[i] = build_fn(i-self.base)
        for i in reversed(xrange(1, self.base)):
            self.tree[i] = query_fn(self.tree[2*i], self.tree[2*i+1])

    def query(self, L, R):
        L += self.base
        R += self.base
        left = right = None
        while L <= R:
            if L & 1:
                left = self.query_fn(left, self.tree[L])
                L += 1
            if R & 1 == 0:
                right = self.query_fn(self.tree[R], right)
                R -= 1
            L //= 2
            R //= 2
        return self.query_fn(left, right)


# number theory, segment tree
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


MAX_N = 10**6
PRIMES = linear_sieve_of_eratosthenes(MAX_N)
ST = SegmentTree(len(PRIMES)-1,
                 build_fn=lambda i: [PRIMES[i+1]-PRIMES[i], [PRIMES[i], PRIMES[i+1]]],
                 query_fn=lambda x, y: y if x is None else x if y is None else min(x, y))
class Solution(object):
    def closestPrimes(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        i = bisect.bisect_left(PRIMES, left)
        j = bisect.bisect_right(PRIMES, right)-1
        return ST.query(i, j-1)[1] if i <= j-1 else [-1]*2
