# Time:  O(n^2 * logn)
# Space: O(n)

import heapq


# heap
class Solution(object):
    def minMoves(self, balance):
        """
        :type balance: List[int]
        :rtype: int
        """
        def clamp(x, l, r):
            return min(max(x, l), r)
    
        def cost(i):
            result = prefix = 0
            max_heap = []
            for j in xrange(len(balance)):
                prefix += balance[(i+j)%len(balance)]
                c = clamp(prefix, 0, total)
                result += abs(prefix-c)
                # heap-based l1 isotonic regression, reference: https://codeforces.com/contest/13/problem/C
                heapq.heappush(max_heap, -c)
                if -max_heap[0] > c:
                    result += -heapq.heappop(max_heap)-c
                    heapq.heappush(max_heap, -c)
            return result

        total = sum(balance)
        return min(cost(i) for i in xrange(len(balance))) if total >= 0 else -1
