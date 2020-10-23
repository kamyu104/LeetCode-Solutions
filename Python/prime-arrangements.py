# Time:  O(n/2 + n/3 + ... + n/p) = O(nlog(logn)), see https://mathoverflow.net/questions/4596/on-the-series-1-2-1-3-1-5-1-7-1-11
# Space: O(n)

class Solution(object):
    def numPrimeArrangements(self, n):
        """
        :type n: int
        :rtype: int
        """
        def count_primes(n):
            if n <= 1:
                return 0
            is_prime = [True]*((n+1)//2)
            cnt = len(is_prime)
            for i in xrange(3, n+1, 2):
                if i*i > n:
                    break
                if not is_prime[i//2]:
                    continue
                for j in xrange(i*i, n+1, 2*i):
                    if not is_prime[j//2]:
                        continue
                    cnt -= 1
                    is_prime[j//2] = False
            return cnt
        
        def factorial(n):
            result = 1
            for i in xrange(2, n+1):
                result = (result*i)%MOD
            return result

        MOD = 10**9+7
        cnt = count_primes(n)
        return factorial(cnt) * factorial(n-cnt) % MOD
