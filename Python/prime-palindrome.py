# Time:  O(n^(3/2))
# Space: O(logn)

# Find the smallest prime palindrome greater than or equal to N.
# Recall that a number is prime if it's only divisors are 1 and itself,
# and it is greater than 1.
#
# For example, 2,3,5,7,11 and 13 are primes.
#
# Recall that a number is a palindrome if it reads the same from
# left to right as it does from right to left.
#
# For example, 12321 is a palindrome.
#
# Example 1:
#
# Input: 6
# Output: 7
# Example 2:
#
# Input: 8
# Output: 11
# Example 3:
#
# Input: 13
# Output: 101
#
# Note:
# - 1 <= N <= 10^8
# - The answer is guaranteed to exist and be less than 2 * 10^8.

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """
        def is_prime(n):
            if n < 2 or n % 2 == 0:
                return n == 2
            return all(n % d for d in xrange(3, int(n**.5) + 1, 2))

        if 8 <= N <= 11:
            return 11
        for i in xrange(10**(len(str(N))//2), 10**5):
            j = int(str(i) + str(i)[-2::-1])
            if j >= N and is_prime(j):
                return j
