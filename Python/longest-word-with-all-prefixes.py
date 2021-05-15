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
        def iter_dfs(words, node):
            result = -1
            stk = [node]
            while stk:
                node = stk.pop()
                if result == -1 or len(words[node["_end"]]) > len(words[result]):
                    result = node["_end"]
                for c in reversed(string.ascii_lowercase):
                    if c not in node or "_end" not in node[c]:
                        continue
                    stk.append(node[c])
            return result       
    
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        trie["_end"] = -1
        for i, word in enumerate(words):
            reduce(dict.__getitem__, word, trie)["_end"] = i
        result = iter_dfs(words, trie)
        return words[result] if result != -1 else "" 


# Time:  O(n)
# Space: O(t), t is the number of nodes in trie
import collections
import string


class Solution2(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        def dfs(words, node, result):
            if result[0] == -1 or len(words[node["_end"]]) > len(words[result[0]]):
                result[0] = node["_end"]
            for c in string.ascii_lowercase:
                if c not in node or "_end" not in node[c]:
                    continue
                dfs(words, node[c], result)
    
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        trie["_end"] = -1
        for i, word in enumerate(words):
            reduce(dict.__getitem__, word, trie)["_end"] = i
        result = [-1]
        dfs(words, trie, result)
        return words[result[0]] if result[0] != -1 else ""
