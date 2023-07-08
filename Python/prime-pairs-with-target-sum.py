# Time:  O(n)
# Space: O(n)

# number theory
class Solution(object):
    def findPrimePairs(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        def linear_sieve_of_eratosthenes(n):
            primes = []
            spf = [-1]*(n+1)  # the smallest prime factor
            for i in xrange(2, n+1):
                if spf[i] == -1:
                    spf[i] = i
                    primes.append(i)
                for p in primes:
                    if i*p > n or p > spf[i]:
                        break
                    spf[i*p] = p
            return spf  # len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n

        spf = linear_sieve_of_eratosthenes(n)
        return [[i, n-i] for i in xrange(2, n//2+1) if spf[i] == i and spf[n-i] == n-i]
