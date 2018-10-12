# Time:  O(n), n is the total sum of the lengths of words
# Space: O(t), t is the number of nodes in trie

import collections
import functools


class Solution(object):
    def minimumLengthEncoding(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words = list(set(words))
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()

        nodes = [functools.reduce(dict.__getitem__, word[::-1], trie)
                 for word in words]

        return sum(len(word) + 1
                   for i, word in enumerate(words)
                   if len(nodes[i]) == 0)

