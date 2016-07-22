# Time:  O(n)
# Space: O(n)
# Description:
#
# Count the number of prime numbers less than a non-negative number, n
#
# Hint: The number n could be in the order of 100,000 to 5,000,000.
#

from math import sqrt

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

            if is_prime[i]:
                for j in xrange(i*i, n, 2*i):
                    if is_prime[j]:
                        num -= 1
                        is_prime[j] = False
        return num
