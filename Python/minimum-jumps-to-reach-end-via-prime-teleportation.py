# Time:  precompute: O(r)
#        runtime:    O(nlogr)
# Space: O(r + nlogr)

import collections


# number theory, bfs
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


MAX_NUM = 10**6
SPF = linear_sieve_of_eratosthenes(MAX_NUM)
class Solution(object):
    def minJumps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        adj = collections.defaultdict(list)
        for i, x in enumerate(nums):
            while x != 1:
                p = SPF[x]
                while x%p == 0:
                    x //= p
                adj[p].append(i)
        dist = [-1]*len(nums)
        dist[0] = 0
        q = [0]
        while q:
            new_q = []
            for i in q:
                if i == len(nums)-1:
                    return dist[-1]
                for di in (-1, +1):
                    ni = i+di
                    if 0 <= ni < len(nums) and dist[ni] == -1:
                        dist[ni] = dist[i]+1
                        new_q.append(ni)
                p = nums[i]
                if SPF[p] != p or p not in adj:
                    continue
                for ni in adj[p]:
                    if dist[ni] != -1:
                        continue
                    dist[ni] = dist[i]+1
                    new_q.append(ni)
                del adj[p]
            q = new_q
        return -1
