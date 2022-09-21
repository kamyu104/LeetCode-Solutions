# Time:  O(n * l), n is the number of words, l is the max length of words
# Space: O(t), t is the size of trie
    
import collections


# trie
class Solution(object):
    def sumPrefixScores(self, words):
        """
        :type words: List[str]
        :rtype: List[int]
        """
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for w in words:
            curr = trie
            for c in w:
                curr = curr[c]
                curr["_cnt"] = curr["_cnt"]+1 if "_cnt" in curr else 1
        result = []
        for w in words:
            cnt = 0
            curr = trie
            for c in w:
                curr = curr[c]
                cnt += curr["_cnt"]
            result.append(cnt)
        return result
