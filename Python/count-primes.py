# Time:  O(n)
# Space: O(n)

# Description:
#
# Count the number of prime numbers less than a non-negative number, n
#
# Hint: The number n could be in the order of 100,000 to 5,000,000.


class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 2:
            return 0
        
        is_prime = [True] * n
        num = n / 2
        for i in xrange(3, n, 2):
            if i * i >= n:
                break

            if not is_prime[i]:
                continue

            for j in xrange(i*i, n, 2*i):
                if not is_prime[j]:
                    continue

                num -= 1
                is_prime[j] = False

        return num

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
