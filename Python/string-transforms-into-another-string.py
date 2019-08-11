# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def canConvert(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: bool
        """
        if str1 == str2:
            return True
        lookup = {}
        for i, j in itertools.izip(str1, str2):
            if lookup.setdefault(i, j) != j:
                return False
        return len(set(str2)) < 26
