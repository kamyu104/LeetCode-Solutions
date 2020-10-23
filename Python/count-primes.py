# Time:  O(n/2 + n/3 + ... + n/p) = O(nlog(logn)), see https://mathoverflow.net/questions/4596/on-the-series-1-2-1-3-1-5-1-7-1-11
# Space: O(n)

class Solution(object):
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 2:
            return 0

        is_prime = [True]*(n//2)
        cnt = len(is_prime)
        for i in xrange(3, n, 2):
            if i * i >= n:
                break
            if not is_prime[i//2]:
                continue
            for j in xrange(i*i, n, 2*i):
                if not is_prime[j//2]:
                    continue
                cnt -= 1
                is_prime[j//2] = False

        return cnt

    def countPrimes2(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
        return sum(primes)

