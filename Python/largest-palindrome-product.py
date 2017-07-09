# Time:  O(10^(2n))
# Space: O(n)

# Find the largest palindrome made from the product of two n-digit numbers.
# Since the result could be very large, you should return the largest palindrome mod 1337.
#
# Example:
# Input: 2
# Output: 987
# Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
#
# Note:
# The range of n is [1,8].

class Solution_TLE(object):
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9
    
        upper, lower = 10**n-1, 10**(n-1)
        for i in reversed(xrange(lower, upper+1)):
            candidate = int(str(i) + str(i)[::-1])
            j = upper
            while j * j >= candidate:
                if candidate % j == 0:
                    return candidate % 1337
                j -= 1
        return -1
