# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def areAlmostEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        diff = []
        for a, b in itertools.izip(s1, s2):
            if a == b:
                continue
            if len(diff) == 2:
                return False
            diff.append([a, b] if not diff else [b, a])
        return not diff or (len(diff) == 2 and diff[0] == diff[1])
