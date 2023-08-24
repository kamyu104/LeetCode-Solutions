# Time:  O(n)
# Space: O(1)

import itertools


# string
class Solution(object):
    def isAcronym(self, words, s):
        """
        :type words: List[str]
        :type s: str
        :rtype: bool
        """
        return len(words) == len(s) and all(w[0] == c for w, c in itertools.izip(words, s))
