# Time:  O(nlogn)
# Space: O(n)

# Alice has a hand of cards, given as an array of integers.
#
# Now she wants to rearrange the cards into groups
# so that each group is size W,
# and consists of W consecutive cards.
#
# Return true if and only if she can.
#
# Example 1:
#
# Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
# Output: true
# Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
# Example 2:
#
# Input: hand = [1,2,3,4,5], W = 4
# Output: false
# Explanation: Alice's hand can't be rearranged into groups of 4.
#
# Note:
# - 1 <= hand.length <= 10000
# - 0 <= hand[i] <= 10^9
# - 1 <= W <= hand.length

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
