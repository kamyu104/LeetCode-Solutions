# Time:  O(n), n is the length of the word
# Space: O(d)

# Implement a magic directory with buildDict, and search methods.
#
# For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
#
# For the method search, you'll be given a word, and judge whether
# if you modify exactly one character into another character in this word,
# the modified word is in the dictionary you just built.
#
# Example 1:
# Input: buildDict(["hello", "leetcode"]), Output: Null
# Input: search("hello"), Output: False
# Input: search("hhllo"), Output: True
# Input: search("hell"), Output: False
# Input: search("leetcoded"), Output: False
# Note:
# You may assume that all the inputs are consist of lowercase letters a-z.
# For contest purpose, the test data is rather small by now.
# You could think about highly efficient algorithm after the contest.
# Please remember to RESET your class variables declared in class MagicDictionary,
# as static/class variables are persisted across multiple test cases. Please see here for more details.

class MagicDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        _trie = lambda: collections.defaultdict(_trie)
        self.trie = _trie()


    def buildDict(self, dictionary):
        """
        Build a dictionary through a list of words
        :type dictionary: List[str]
        :rtype: void
        """
        for word in dictionary:
            reduce(dict.__getitem__, word, self.trie).setdefault("_end")


    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        def find(word, curr, i, mistakeAllowed): 
            if i == len(word):
                return "_end" in curr and not mistakeAllowed

            if word[i] not in curr: 
                return any(find(word, curr[c], i+1, False) for c in curr if c != "_end") \
                           if mistakeAllowed else False 
            
            if mistakeAllowed: 
                return find(word, curr[word[i]], i+1, True) or \
                       any(find(word, curr[c], i+1, False) \
                           for c in curr if c not in ("_end", word[i]))
            return find(word, curr[word[i]], i+1, False)

        return find(word, self.trie, 0, True)    
        


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
