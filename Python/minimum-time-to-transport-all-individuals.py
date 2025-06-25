# Time:  O((n * m * 2^n + m * 3^n) * log(n * m * 2^n + m * 3^n)) = O(m * 3^n * log(m * 3^n))
# Space: O(n * m * 2^n + m * 3^n) = O(m * 3^n)

import heapq


# dijkstra's algorithm, submask enumeration
class Solution(object):
    def minTime(self, n, k, m, time, mul):
        """
        :type n: int
        :type k: int
        :type m: int
        :type time: List[int]
        :type mul: List[float]
        :rtype: float
        """
        def update(d, r, s, mask, submask):
            t = lookup[submask]*mul[s]
            nr = r^1
            ns = (s+int(t))%m
            new_mask = mask^submask
            nd = d+t
            if dist[nr][ns][new_mask] > nd:
                dist[nr][ns][new_mask] = nd
                heapq.heappush(min_heap, (nd, nr, ns, new_mask))
    
        popcount = [0]*(1<<n)  # for better performance
        for i in xrange(1, (1<<n)):
            popcount[i] = popcount[i>>1]+(i&1)
        lookup = [max(time[i] for i in xrange(n) if mask&(1<<i)) if mask else 0 for mask in xrange(1<<n)]  # Time: O(n * 2^n)
        INF = float("inf")
        dist = [[[INF]*(1<<n) for _ in xrange(m)] for _ in xrange(2)]
        dist[0][0][(1<<n)-1] = 0.0
        min_heap = [(0.0, 0, 0, (1<<n)-1)]
        while min_heap:
            d, r, s, mask = heapq.heappop(min_heap)  # Total Time: O((n * m * 2^n + m * 3^n) * log(n * m * 2^n + m * 3^n))
            if d != dist[r][s][mask]:
                continue
            if mask == 0:
                assert(r == 1)
                return d
            if r == 0:
                submask = mask
                while submask:  # Total Time: O(m * 3^n)
                    if popcount[submask] <= k:
                        update(d, r, s, mask, submask)
                    submask = (submask-1)&mask
            else:
                for i in xrange(n):  # Total Time: O(n * m * 2^n)
                    if mask&(1<<i):
                        continue
                    update(d, r, s, mask, 1<<i)
        return -1.0
