# Time:  init: O(n), lookup: O(a + b), a, b is occurences of word1, word2
# Space: O(n)

import collections


class WordDistance(object):
    # initialize your data structure here.
    # @param {string[]} words
    def __init__(self, words):
        self.wordIndex = collections.defaultdict(list)
        for i in xrange(len(words)):
            self.wordIndex[words[i]].append(i)

    # @param {string} word1
    # @param {string} word2
    # @return {integer}
    # Adds a word into the data structure.
    def shortest(self, word1, word2):
        indexes1 = self.wordIndex[word1]
        indexes2 = self.wordIndex[word2]

        i, j, dist = 0, 0, float("inf")
        while i < len(indexes1) and j < len(indexes2):
            dist = min(dist, abs(indexes1[i] - indexes2[j]))
            if indexes1[i] < indexes2[j]:
                i += 1
            else:
                j += 1

        return dist

