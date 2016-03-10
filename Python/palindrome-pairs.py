# Time:  O(n * k^2), n is the number of the words,
#                    k is the max length of the words.
# Space: O(n * k)

# Given a list of unique words. Find all pairs of indices (i, j)
# in the given list, so that the concatenation of the two words, 
# i.e. words[i] + words[j] is a palindrome.
#
# Example 1:
# Given words = ["bat", "tab", "cat"]
# Return [[0, 1], [1, 0]]
# The palindromes are ["battab", "tabbat"]
# Example 2:
# Given words = ["abcd", "dcba", "lls", "s", "sssll"]
# Return [[0, 1], [1, 0], [3, 2], [2, 4]]
# The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]


class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        res = [] 
        lookup = {}
        for i, word in enumerate(words):
            lookup[word] = i

        for i in xrange(len(words)):
            for j in xrange(len(words[i]) + 1):
                prefix = words[i][j:]
                suffix = words[i][:j]
                if prefix == prefix[::-1] and \
                   suffix[::-1] in lookup and lookup[suffix[::-1]] != i:
                    res.append([i, lookup[suffix[::-1]]])
                if j > 0 and suffix == suffix[::-1] and \
                   prefix[::-1] in lookup and lookup[prefix[::-1]] != i:
                    res.append([lookup[prefix[::-1]], i])
        return res


# Time:  O(n * k^2), n is the number of the words, k is the max length of the words.
#                    k is the max length of the words.
# Space: O(n * k)
# Trie solution.
class TrieNode:
    def __init__(self):
        self.word_idx = -1
        self.leaves = {}

    def insert(self, word, i):
        cur = self
        for c in word:
            if not c in cur.leaves:
                cur.leaves[c] = TrieNode()
            cur = cur.leaves[c]
        cur.word_idx = i

    def find(self, s, idx, res):
        cur = self
        for i in reversed(xrange(len(s))):
            if s[i] in cur.leaves:
                cur = cur.leaves[s[i]]
                if cur.word_idx not in (-1, idx) and \
                   self.is_palindrome(s, i - 1):
                    res.append([cur.word_idx, idx])
            else:
                break

    def is_palindrome(self, s, j):
        i = 0
        while i <= j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

class Solution_MLE(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        res = []
        trie = TrieNode()
        for i in xrange(len(words)):
            trie.insert(words[i], i)

        for i in xrange(len(words)):
            trie.find(words[i], i, res)

        return res
