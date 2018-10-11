# Time:  O(sqrt(n))
# Space: O(1)

class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        p = 2
        # the answer is the sum of prime factors
        while p**2 <= n:
            while n % p == 0:
                result += p
                n //= p
            p += 1
        if n > 1:
            result += n
        return result

