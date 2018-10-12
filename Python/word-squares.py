# Time:  O(n^2 * n!)
# Space: O(n^2)

class TrieNode(object):
    def __init__(self):
        self.indices = []
        self.children = [None] * 26

    def insert(self, words, i):
        cur = self
        for c in words[i]:
            if not cur.children[ord(c)-ord('a')]:
                cur.children[ord(c)-ord('a')] = TrieNode()
            cur = cur.children[ord(c)-ord('a')]
            cur.indices.append(i)


class Solution(object):
    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """
        result = []

        trie = TrieNode()
        for i in xrange(len(words)):
            trie.insert(words, i)

        curr = []
        for s in words:
            curr.append(s)
            self.wordSquaresHelper(words, trie, curr, result)
            curr.pop()

        return result

    def wordSquaresHelper(self, words, trie, curr, result):
        if len(curr) >= len(words[0]):
            return result.append(list(curr))

        node = trie
        for s in curr:
            node = node.children[ord(s[len(curr)]) - ord('a')]
            if not node:
                return

        for i in node.indices:
            curr.append(words[i])
            self.wordSquaresHelper(words, trie, curr, result)
            curr.pop()

