# Time:  O(m + n), m is the number of prefix match, n is the number of suffix match
# Space: O(t * w), t is the number of nodes in trie, w is the number of words

class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        def insert(trie, word, i):
            def add_word(cur, i):
                if "_words" not in cur:
                    cur["_words"] = []
                cur["_words"].append(i)
                
            cur = trie
            add_word(cur, i)
            for c in word:
                cur = cur[c]
                add_word(cur, i)
                
        _trie = lambda: collections.defaultdict(_trie)
        self.__prefix_trie = _trie()
        self.__suffix_trie = _trie()
        for i in reversed(xrange(len(words))):
            insert(self.__prefix_trie, words[i], i)
            insert(self.__suffix_trie, words[i][::-1], i)

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        def find(trie, word):
            cur = trie
            for c in word:
                if c not in cur:
                    return []
                cur = cur[c]
            return cur["_words"]
        
        prefix_match = find(self.__prefix_trie, prefix)
        suffix_match = find(self.__suffix_trie, suffix[::-1])
        i, j = 0, 0
        while i != len(prefix_match) and j != len(suffix_match):
            if prefix_match[i] == suffix_match[j]:
                return prefix_match[i]
            elif prefix_match[i] > suffix_match[j]:
                i += 1
            else:
                j += 1
        return -1
        
# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
