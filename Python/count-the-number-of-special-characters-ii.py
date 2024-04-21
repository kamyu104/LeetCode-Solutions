# Time:  O(n + 26)
# Space: O(26)

import itertools


# hash table
class Solution(object):
    def numberOfSpecialChars(self, word):
        """
        :type word: str
        :rtype: int
        """
        lookup1 = [len(word)]*26
        lookup2 = [-1]*26
        for i, x in enumerate(word):
            if x.islower():
                lookup1[ord(x)-ord('a')] = i
            elif lookup2[ord(x)-ord('A')] == -1:
                lookup2[ord(x)-ord('A')] = i
        return sum(x < y for x, y in itertools.izip(lookup1, lookup2))
