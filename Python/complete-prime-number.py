# Time:  O(logn * sqrt(n))
# Space: O(1)

# number theory
class Solution(object):
    def completePrime(self, num):
        """
        :type num: int
        :rtype: bool
        """
        def is_prime(n):
            if (n <= 1) or (n != 2 and n%2 == 0):
                return False
            for i in xrange(3, n+1, 2):
                if i*i > n:
                    break
                if n%i == 0:
                    return False
            return True

        suffix, base = 0, 1
        while num:
            if not is_prime(num):
                return False
            suffix += (num%10)*base
            if not is_prime(suffix):
                return False
            num //= 10
            base *= 10
        return True
