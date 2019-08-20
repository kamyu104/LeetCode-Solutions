# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        count = collections.Counter(chars)
        return sum(len(word) for word in words if not collections.Counter(word)-count)
