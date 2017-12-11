# Time:  ctor:   O(w * l), w is the number of words, l is the word length on average
#        search: O(l + m + n), m is the number of prefix match, n is the number of suffix match
# Space: O(w * l)

class Trie(object):
    
    def __init__(self):
        _trie = lambda: collections.defaultdict(_trie)
        self.__trie = _trie()

    def insert(self, word, i):
        def add_word(cur, i):
            if "_words" not in cur:
                cur["_words"] = []
            cur["_words"].append(i)

        cur = self.__trie
        add_word(cur, i)
        for c in word:
            cur = cur[c]
            add_word(cur, i)

    def find(self, word):
        cur = self.__trie
        for c in word:
            if c not in cur:
                return []
            cur = cur[c]
        return cur["_words"]


class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """   
        self.__prefix_trie = Trie()
        self.__suffix_trie = Trie()
        for i in reversed(xrange(len(words))):
            self.__prefix_trie.insert(words[i], i)
            self.__suffix_trie.insert(words[i][::-1], i)

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """        
        prefix_match = self.__prefix_trie.find(prefix)
        suffix_match = self.__suffix_trie.find(suffix[::-1])
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
