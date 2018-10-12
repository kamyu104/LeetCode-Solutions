# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        diff = []
        for a, b in itertools.izip(A, B):
            if a != b:
                diff.append((a, b))
                if len(diff) > 2:
                    return False
        return (not diff and len(set(A)) < len(A)) or \
               (len(diff) == 2 and diff[0] == diff[1][::-1])

