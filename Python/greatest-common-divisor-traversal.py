# Time:  precompute: O(sqrt(r)), r = max(nums)
#        runtime:    O(nlogr)
# Space: O(sqrt(r) + nlogr)

# linear sieve of eratosthenes, number theory, bfs
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


MAX_NUM = 10**5
PRIMES = linear_sieve_of_eratosthenes(int(MAX_NUM**0.5))
class Solution(object):
    def canTraverseAllPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def prime_factors(x):
            factors = collections.Counter()
            for p in PRIMES:
                if x < p:
                    break
                while x%p == 0:
                    factors[p] += 1
                    x //= p
            if x != 1:
                factors[x] += 1
            return factors

        def bfs():
            lookup = [False]*len(nums)
            lookup[0] = True
            q = [0]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
            return all(lookup)

        adj = [[] for _ in xrange(len(nums))]
        lookup = {}
        for i, x in enumerate(nums):
            for p in prime_factors(x):
                if p not in lookup:
                    lookup[p] = i
                    continue
                adj[i].append(lookup[p])
                adj[lookup[p]].append(i)
        return bfs()
