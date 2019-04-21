# Time:  ctor:  O(n + p^2), n is the total size of patterns
#                         , p is the count of patterns
#        query: O(m + z), m is the total size of query string
#                       , z is the number of all matched strings 
# Space: O(t + p^2), t is the total size of ac automata trie,

# Aho–Corasick automata
# reference:
# - http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
# - http://algo.pw/algo/64/python

import collections


class AhoNode(object):
    def __init__(self):
        self.children = collections.defaultdict(AhoNode)
        self.suffix = None
        self.outputs = []


class AhoTrie(object):

    def query(self, letter):
        while self.__node and letter not in self.__node.children:
            self.__node = self.__node.suffix
        if not self.__node:
            self.__node = self.__root
            return False
 
        self.__node = self.__node.children[letter]
        result = self.__node.outputs
        return len(result) > 0
    
    def __init__(self, patterns):
        self.__root = self.__create_ac_trie(patterns)
        self.__create_ac_suffix_and_output_links(self.__root)
        self.__node = self.__root
    
    def __create_ac_trie(self, patterns):  # Time:  O(n), Space: O(t)
        root = AhoNode()
        for i, pattern in enumerate(patterns):
            node = root
            for c in pattern:
                node = node.children[c]
            node.outputs.append(i)
        return root

    def __create_ac_suffix_and_output_links(self, root):  # Time:  O(n + p^2), Space: O(t + p^2)
        queue = collections.deque()
        for node in root.children.itervalues():
            queue.append(node)
            node.suffix = root

        while queue:
            node = queue.popleft()
            for key, child in node.children.iteritems():
                queue.append(child)
                fail = node.suffix
                while fail and key not in fail.children:
                    fail = fail.suffix
                child.suffix = fail.children[key] if fail else root
                child.outputs += child.suffix.outputs  # Time: O(p^2)


class StreamChecker(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.__trie = AhoTrie(words)

    def query(self, letter):
        """
        :type letter: str
        :rtype: bool
        """
        return self.__trie.query(letter)
        

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
