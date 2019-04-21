# Time:  ctor:  O(n), n is the total size of patterns
#        query: O(m + z), m is the total size of query string
#                       , z is the number of all matched strings 
# Space: O(t), t is the total size of ac automata trie

# Aho–Corasick automata
# reference:
# 1. http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
# 2. http://algo.pw/algo/64/python

import collections


class AhoNode(object):
    def __init__(self):
        self.states = collections.defaultdict(AhoNode)
        self.output = None
        self.suffix = None
        self.id = []


class AhoTrie(object):

    def query(self, letter):
        while self.__node and letter not in self.__node.states:
            self.__node = self.__node.suffix
        if not self.__node:
            self.__node = self.__root
            return False
 
        result = []
        self.__node = self.__node.states[letter]
        if self.__node.id:
            for i in self.__node.id:
                result.append(self.__patterns[i])
        tmp = self.__node.output
        while tmp:
            for i in tmp.id:
                result.append(self.__patterns[i])
            tmp = tmp.output
        return len(result) > 0
    
    def __init__(self, patterns):
        self.__patterns = patterns
        self.__root = self.__create_ac_trie(patterns)
        self.__create_ac_suffix_and_output_links(self.__root)
        self.__node = self.__root
    
    def __create_ac_trie(self, patterns):  # Time:  O(n), Space: O(t)
        root = AhoNode()
        for i, pattern in enumerate(patterns):
            node = root
            for c in pattern:
                node = node.states[c]
            node.id.append(i)
        return root

    def __create_ac_suffix_and_output_links(self, root):  # Time:  O(n), Space: O(t)
        queue = collections.deque()
        for node in root.states.itervalues():
            queue.append(node)
            node.suffix = root

        while queue:
            node = queue.popleft()
            for key, child in node.states.iteritems():
                queue.append(child)
                fail = node.suffix
                while fail and key not in fail.states:
                    fail = fail.suffix
                child.suffix = fail.states[key] if fail else root
                child.output = child.suffix if child.suffix.id else child.suffix.output


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
