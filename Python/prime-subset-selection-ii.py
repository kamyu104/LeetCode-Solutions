# Time:  O(n + (n / logn) * s)
# Space: O(n + (n / logn) * s)

# number theory, knapsack dp, greedy, backtracing
def linear_sieve_of_eratosthenes(n):  # Time: O(n), Space: O(n)
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

class Solution(object):
    def maxPrimeSubset(self, n, s):
        """
        :type n: int
        :type s: int
        :rtype: List[int]
        """
        INF = float("inf")
        primes = linear_sieve_of_eratosthenes(n)
        dp = [[INF]*(s+1) for _ in xrange(len(primes)+1)]
        dp[-1][0] = 0
        for i in reversed(xrange(len(primes))):
            for j in xrange(len(dp[i])):
                dp[i][j] = min(dp[i+1][j], dp[i+1][j-primes[i]]+1 if j-primes[i] >= 0 else INF)
        target = next(j for j in reversed(xrange(len(dp[0]))) if dp[0][j] is not INF)
        result = []
        for i in xrange(len(primes)):
            if target-primes[i] < 0:
                break
            if dp[i+1][target-primes[i]] != dp[i][target]-1:
                continue
            result.append(primes[i])
            target -= primes[i]
        return result


# Time:  O(n + (n / logn) * s * l), l = max number of primes whose sum is at most s (when s = 1000, l = 24)
# Space: O(n + s * l)
# number theory, knapsack dp
class Solution2(object):
    def maxPrimeSubset(self, n, s):
        """
        :type n: int
        :type s: int
        :rtype: List[int]
        """
        INF = float("inf")
        primes = linear_sieve_of_eratosthenes(n)
        dp = [(INF, [])]*(s+1)
        dp[0] = (0, [])
        for p in reversed(primes):
            for i in reversed(xrange(p, s+1)):
                dp[i] = min(dp[i], (dp[i-p][0]+1, [p]+dp[i-p][1]))
        return next(dp[i][1] for i in reversed(xrange(len(dp))) if dp[i][0] is not INF)
