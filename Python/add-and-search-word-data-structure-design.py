# Time:  O(min(n, h)), per operation
# Space: O(min(n, h))
#
# Design a data structure that supports the following two operations:
#
# void addWord(word)
# bool search(word)
# search(word) can search a literal word or a regular expression string containing only letters a-z or .. 
# A . means it can represent any one letter.
#
# For example:
#
# addWord("bad")
# addWord("dad")
# addWord("mad")
# search("pad") -> false
# search("bad") -> true
# search(".ad") -> true
# search("b..") -> true
# Note:
# You may assume that all words are consist of lowercase letters a-z.
#

class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.flag = False
        self.children = {}
        
class WordDictionary:
    def __init__(self):
        self.root = TrieNode()
        
    # @param {string} word
    # @return {void}
    # Adds a word into the data structure.
    def addWord(self, word):
        curr = self.root
        for c in word:
            if not c in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.flag = True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the data structure. A word could
    # contain the dot character '.' to represent any one letter.
    def search(self, word):
        return self.searchHelper(word, 0, self.root)
        
    def searchHelper(self, word, start, curr):
        if start == len(word):
            return curr.flag
        if word[start] in curr.children:
            return self.searchHelper(word, start+1, curr.children[word[start]])
        elif word[start] == '.':
            for c in curr.children:
                if self.searchHelper(word, start+1, curr.children[c]):
                    return True
       
        return False

# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")
