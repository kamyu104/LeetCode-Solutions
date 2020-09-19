# Time:  O(26 * d * l) = O(d * l), d is the size of wordlist, l is the max length of words
# Space: O(d * l)

from string import ascii_lowercase


# two-end bfs
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        words = set(wordList)
        if endWord not in words:
            return 0
        is_found, left, right, is_reversed = False, {beginWord}, {endWord},  False
        ladder = 2
        while left:
            words -= set(left)
            new_left = set()
            for word in left:
                for new_word in [word[:i]+c+word[i+1:] for i in xrange(len(beginWord)) for c in ascii_lowercase]:
                    if new_word not in words:
                        continue
                    if new_word in right: 
                        return ladder
                    else: 
                        new_left.add(new_word)
            left = new_left
            ladder += 1
            if len(left) > len(right): 
                left, right, is_reversed = right, left, not is_reversed
        return 0


# Time:  O(26 * d * l) = O(d * l), d is the size of wordlist, l is the max length of words
# Space: O(d * l)
class Solution2(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        lookup = set(wordList)
        if endWord not in lookup:
            return 0
        ladder = 2
        q = [beginWord]
        while q:
            new_q = []
            for word in q:
                for i in xrange(len(word)):
                    for j in ascii_lowercase:
                        new_word = word[:i] + j + word[i+1:]
                        if new_word == endWord:
                            return ladder
                        if new_word in lookup:
                            lookup.remove(new_word)
                            new_q.append(new_word)
            q = new_q
            ladder += 1
        return 0
