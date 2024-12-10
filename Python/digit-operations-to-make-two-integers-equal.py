# Time:  O(nlogn)
# Space: O(n)

import heapq


# number theory, dijkstra's algorithm
class Solution(object):
    def minOperations(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
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
            return spf
            
        def dijkstra(start, target):
            if spf[start] == start:
                return -1
            lookup = set()
            min_heap = [(start, start)]
            while min_heap:
                curr, i = heapq.heappop(min_heap)
                if i in lookup:
                    continue
                lookup.add(i)
                if i == target:
                    return curr
                base = 1
                while base <= i:
                    x = i//base
                    for d in (-1, 1):
                        if (1 if x <= 9 else 0) <= x%10+d <= 9 and spf[i+d*base] != i+d*base and i+d*base not in lookup:
                            heapq.heappush(min_heap, (curr+(i+d*base), i+d*base))
                    base *= 10
            return -1
        
        base = 1
        while base < max(n, m):
            base *= 10
        spf = linear_sieve_of_eratosthenes(base)
        return dijkstra(n, m)
