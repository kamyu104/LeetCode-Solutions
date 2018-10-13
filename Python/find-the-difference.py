# Time:  O(n)
# Space: O(1)

import operator
import collections
from functools import reduce


class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        return chr(reduce(operator.xor, map(ord, s), 0) ^ reduce(operator.xor, map(ord, t), 0))

    def findTheDifference2(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        t = list(t)
        s = list(s)
        for i in s:
            t.remove(i)
        return t[0]

    def findTheDifference3(self, s, t):
        return chr(reduce(operator.xor, map(ord, s + t)))

    def findTheDifference4(self, s, t):
        return list((collections.Counter(t) - collections.Counter(s)))[0]

    def findTheDifference5(self, s, t):
        s, t = sorted(s), sorted(t)
        return t[-1] if s == t[:-1] else [x[1] for x in zip(s, t) if x[0] != x[1]][0]


