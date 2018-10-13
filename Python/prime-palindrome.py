# Time:  O(n^(1/2) * (logn + n^(1/2)))
# Space: O(logn)


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

