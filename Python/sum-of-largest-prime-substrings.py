# Time:  O(n^2 * sqrt(r) + n^2 * logn)
# Space: O(n^2)

# number theory, sort
class Solution(object):
    def sumOfLargestPrimes(self, s):
        """
        :type s: str
        :rtype: int
        """
        def is_prime(n):
            if n == 1:
                return False
            if n in (2, 3):
                return True
            if n%2 == 0 or n%3 == 0:
                return False
            for i in xrange(5, n, 6):
                if i*i > n:
                    break
                if n%i == 0 or n%(i+2) == 0:
                    return False
            return True
    
        primes = set()
        for i in xrange(len(s)):
            curr = 0
            for j in xrange(i, len(s)):
                curr = curr*10+int(s[j])
                if is_prime(curr):
                    primes.add(curr)
        return sum(sorted(primes)[-3:])
