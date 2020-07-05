# Time:  O(nlogn)
# Space: O(n)

import collections


class BIT(object):  # Fenwick Tree, 1-indexed
    def __init__(self, n):
        self.__bit = [0] * n

    def add(self, i, val):
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def sum(self, i):
        result = 0
        while i > 0:
            result += self.__bit[i]
            i -= (i & -i)
        return result


class Solution(object):
    def minInteger(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        lookup = collections.defaultdict(collections.deque)
        bit = BIT(len(num)+1)
        for i, d in enumerate(num):
            bit.add(i+1, 1)
            lookup[int(d)].append(i+1)
        result = []
        for _ in xrange(len(num)):
            for d in xrange(10):
                if lookup[d] and bit.sum(lookup[d][0]-1) <= k:
                    k -= bit.sum(lookup[d][0]-1)
                    bit.add(lookup[d].popleft(), -1)
                    result.append(d)
                    break
        return "".join(map(str, result))
