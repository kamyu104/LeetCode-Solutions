# Time:  O(n), per operation
# Space: O(1)
#
# Implement a trie with insert, search, and startsWith methods.
#
# Note:
# You may assume that all inputs are consist of lowercase letters a-z.
#

class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.is_string = False
        self.leaves = {}
        

class Trie:

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        cur = self.root
        for c in word:
            if not c in cur.leaves:
                cur.leaves[c] = TrieNode()
            cur = cur.leaves[c]
        cur.is_string = True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        node = self.childSearch(word)
        if node:
            return node.is_string
        return False        

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        return not self.childSearch(prefix)

    def childSearch(self, word):
        cur = self.root
        for c in word:
            if c in cur.leaves:
                cur = cur.leaves[c]
            else:
                return None
        return cur

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")
