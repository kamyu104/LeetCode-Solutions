# Time:  O(n)
# Space: O(t), t is the number of nodes in trie

import collections
import string


class Solution(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        def dfs(trie, curr, result):
            if len(curr) > len(result):
                result[:] = curr
            for c in string.ascii_lowercase:
                if c not in trie or "_end" not in trie[c]:
                    continue
                curr.append(c)
                dfs(trie[c], curr, result)
                curr.pop()
    
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for word in words:
            reduce(dict.__getitem__, word, trie).setdefault("_end")
        result = []
        dfs(trie, [], result)
        return "".join(result)
