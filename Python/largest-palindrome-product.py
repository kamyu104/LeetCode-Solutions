# Time:  O(10^(2n))
# Space: O(n)

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

