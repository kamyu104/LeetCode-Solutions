# Time:  ctor:   O(w * l^2), w is the number of words, l is the word length on average
#        search: O(p + s)  , p is the length of the prefix, s is the length of the suffix,
# Space: O(t), t is the number of trie nodes

# Given many words, words[i] has weight i.
#
# Design a class WordFilter that supports one function,
# WordFilter.f(String prefix, String suffix).
# It will return the word with given prefix and suffix with maximum weight.
# If no word exists, return -1.
#
# Examples:
# Input:
# WordFilter(["apple"])
# WordFilter.f("a", "e") // returns 0
# WordFilter.f("b", "") // returns -1
# Note:
# words has length in range [1, 15000].
# For each test case, up to words.length queries WordFilter.f may be made.
# words[i] has length in range [1, 10].
# prefix, suffix have lengths in range [0, 10].
# words[i] and prefix, suffix queries consist of lowercase letters only.

class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """   
        _trie = lambda: collections.defaultdict(_trie)
        self.__trie = _trie()

        for weight, word in enumerate(words):
            word += '#'
            for i in xrange(len(word)):
                cur = self.__trie
                cur["_weight"] = weight
                for j in xrange(i, 2*len(word)-1):
                    cur = cur[word[j%len(word)]]
                    cur["_weight"] = weight
                    
    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        cur = self.__trie
        for letter in suffix + '#' + prefix:
            if letter not in cur:
                return -1
            cur = cur[letter]
        return cur["_weight"]


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
