# Time:  O(n * l)
# Space: O(t)

import collections


# trie
class Solution(object):
    def countPrefixSuffixPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        result = 0
        for w in words:
            curr = trie
            for i in xrange(len(w)):
                curr = curr[w[i], w[~i]]
                result += curr["_cnt"] if "_cnt" in curr else 0
            curr["_cnt"] = curr["_cnt"]+1 if "_cnt" in curr else 1
        return result


# Time:  O(n^2 * l)
# Space: O(1)
# brute force
class Solution2(object):
    def countPrefixSuffixPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        def check(i, j):
            return words[j].startswith(words[i]) and words[j].endswith(words[i])
    
        return sum(check(i, j) for i in xrange(len(words)) for j in xrange(i+1, len(words)))
