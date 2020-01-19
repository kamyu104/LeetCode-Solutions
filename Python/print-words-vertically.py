# Time:  O(n)
# Space: O(n)

import itertools


class Solution(object):
    def printVertically(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        return ["".join(c).rstrip() for c in itertools.izip_longest(*s.split(), fillvalue=' ')]
