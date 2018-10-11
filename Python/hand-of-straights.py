# Time:  O(nlogn)
# Space: O(n)

import collections
import heapq

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

class Solution(object):
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        if len(hand) % W:
            return False

        counts = collections.defaultdict(int)
        for i in hand:
            counts[i] += 1

        min_heap = hand[:]
        heapq.heapify(min_heap)
        for _ in xrange(len(min_heap)//W):
            while counts[min_heap[0]] == 0:
                heapq.heappop(min_heap)
            start = heapq.heappop(min_heap)
            for _ in xrange(W):
                counts[start] -= 1
                if counts[start] < 0:
                    return False
                start += 1
        return True

