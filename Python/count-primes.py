# Time:  O(n/2 + n/3 + ... + n/p) = O(nlog(logn)), see https://mathoverflow.net/questions/4596/on-the-series-1-2-1-3-1-5-1-7-1-11
# Space: O(n)

class Solution(object):
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 2:
            return 0

        is_prime = [True]*(n//2)
        cnt = len(is_prime)
        for i in xrange(3, n, 2):
            if i * i >= n:
                break
            if not is_prime[i//2]:
                continue
            for j in xrange(i*i, n, 2*i):
                if not is_prime[j//2]:
                    continue
                cnt -= 1
                is_prime[j//2] = False

        return cnt


# Time:  O(n)
# Space: O(n)
class Solution_TLE(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
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
            return primes
    
        return len(linear_sieve_of_eratosthenes(n-1))
