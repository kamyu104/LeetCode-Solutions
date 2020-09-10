# Time:  O(m * n * 4 * 3^(h - 1)) ~= O(m * n * 3^h), h is the height of trie
# Space: O(t), t is the number of nodes in trie

class TrieNode(object):
    # Initialize your data structure here.
    def __init__(self):
        self.is_string = False
        self.leaves = {}

    # Inserts a word into the trie.
    def insert(self, word):
        cur = self
        for c in word:
            if not c in cur.leaves:
                cur.leaves[c] = TrieNode()
            cur = cur.leaves[c]
        cur.is_string = True


class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        visited = [[False for j in xrange(len(board[0]))] for i in xrange(len(board))]
        result = {}
        trie = TrieNode()
        for word in words:
            trie.insert(word)

        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                self.findWordsRecu(board, trie, 0, i, j, visited, [], result)

        return result.keys()

    def findWordsRecu(self, board, trie, cur, i, j, visited, cur_word, result):
        if not trie or i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or visited[i][j]:
            return

        if board[i][j] not in trie.leaves:
            return

        cur_word.append(board[i][j])
        next_node = trie.leaves[board[i][j]]
        if next_node.is_string:
            result["".join(cur_word)] = True

        visited[i][j] = True
        self.findWordsRecu(board, next_node, cur + 1, i + 1, j, visited, cur_word, result)
        self.findWordsRecu(board, next_node, cur + 1, i - 1, j, visited, cur_word, result)
        self.findWordsRecu(board, next_node, cur + 1, i, j + 1, visited, cur_word, result)
        self.findWordsRecu(board, next_node, cur + 1, i, j - 1, visited, cur_word, result)
        visited[i][j] = False
        cur_word.pop()
