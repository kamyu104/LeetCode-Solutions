# Time:  O(n * k^2), n is the number of the words, k is the max length of the words.
# Space: O(n * k)

import collections


class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def is_palindrome(s, i, j):
            while i < j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True
 
        res = []
        lookup = collections.defaultdict(dict)
        for i, word in enumerate(words):
            lookup[len(word)][word] = i

        for i in xrange(len(words)):
            for j in xrange(len(words[i]) + 1):
                if j in lookup and is_palindrome(words[i], j, len(words[i])-1):
                    suffix = words[i][:j][::-1]
                    bucket = lookup[len(suffix)]
                    if suffix in bucket and bucket[suffix] != i:
                        res.append([i, bucket[suffix]])
                if j > 0 and len(words[i])-j in lookup and is_palindrome(words[i], 0, j-1):
                    prefix = words[i][j:][::-1]
                    bucket = lookup[len(prefix)]
                    if prefix in bucket and bucket[prefix] != i:
                        res.append([bucket[prefix], i])
        return res


# Time:  O(n * k^2), n is the number of the words, k is the max length of the words.
# Space: O(n * k^2)
# Manacher solution.
class Solution_TLE(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def manacher(s, P):
            def preProcess(s):
                if not s:
                    return ['^', '$']
                T = ['^']
                for c in s:
                    T +=  ["#", c]
                T += ['#', '$']
                return T

            T = preProcess(s)
            center, right = 0, 0
            for i in xrange(1, len(T) - 1):
                i_mirror = 2 * center - i
                if right > i:
                    P[i] = min(right - i, P[i_mirror])
                else:
                    P[i] = 0
                while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                    P[i] += 1
                if i + P[i] > right:
                    center, right = i, i + P[i]

        prefix, suffix = collections.defaultdict(list), collections.defaultdict(list)
        for i, word in enumerate(words):
            P = [0] * (2 * len(word) + 3)
            manacher(word, P)
            for j in xrange(len(P)):
                if j - P[j] == 1:
                    prefix[word[(j + P[j]) // 2:]].append(i)
                if j + P[j] == len(P) - 2:
                    suffix[word[:(j - P[j]) // 2]].append(i)
        res = []
        for i, word in enumerate(words):
            for j in prefix[word[::-1]]:
                if j != i:
                    res.append([i, j])
            for j in suffix[word[::-1]]:
                if len(word) != len(words[j]):
                    res.append([j, i])
        return res


# Time:  O(n * k^2), n is the number of the words, k is the max length of the words.
# Space: O(n * k)
# Trie solution.
class TrieNode(object):
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

