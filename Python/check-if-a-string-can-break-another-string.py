# Time:  O(nlogn)
# Space: O(1)

import itertools


class Solution(object):
    def checkIfCanBreak(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        return not {1, -1}.issubset(set(cmp(a, b) for a, b in itertools.izip(sorted(s1), sorted(s2))))


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def checkIfCanBreak(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        s1, s2 = sorted(s1), sorted(s2)
        return all(a >= b for a, b in izip(s1, s2)) or \
               all(a <= b for a, b in izip(s1, s2))
