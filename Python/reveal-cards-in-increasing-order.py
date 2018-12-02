# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        d = collections.deque()
        deck.sort(reverse=True)
        for i in deck:
            if d:
                d.appendleft(d.pop())
            d.appendleft(i)
        return list(d)
