# Time:  O(n * l)
# Space: O(1)

import itertools


class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def match(word):
            lookup = {}
            for x, y in itertools.izip(pattern, word):
                if lookup.setdefault(x, y) != y:
                    return False
            return len(set(lookup.values())) == len(lookup.values())

        return filter(match, words)

